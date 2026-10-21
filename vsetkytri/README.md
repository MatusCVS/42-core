*This project has been created as part of the 42 curriculum by moaks and mmiklovi.*
 
# push_swap
 
## Description
 
`push_swap` sorts a list of integers using two stacks (`a` and `b`) and a fixed set of 11 operations
(`sa sb ss pa pb ra rb rr rra rrb rrr`). The program prints, on standard output, a sequence of
operations that leaves the numbers sorted in ascending order in stack `a` (smallest on top) with
stack `b` empty. The goal is to keep that sequence as short as possible.
 
The project goes beyond "just sort it": it implements **four strategies** with different
complexity classes, measures how disordered the input is, and can pick a strategy at runtime.
All complexities in this document are counted in **number of push_swap operations produced**,
not in CPU time of a classical array algorithm.
 
| Strategy | Flag | Algorithm | Complexity (in operations) |
|---|---|---|---|
| Simple | `--simple` | Selection sort adaptation | O(n²) |
| Medium | `--medium` | Chunk-based sort | O(n√n) |
| Complex | `--complex` | LSD radix sort on ranks | O(n log n) |
| Adaptive | `--adaptive` (default) | Chooses one of the above from the measured disorder |
 
A benchmark mode (`--bench`) prints statistics to `stderr`, and a bonus `checker` program verifies
that a sequence of operations really sorts a given input.
 
### Project layout
 
| File | Role |
|---|---|
| `main.c` | Entry point, strategy selection (`adaptive_sort`, `dispatcher`) |
| `mode.c` | Flag parsing (`parse_flags`), operation counter (`count_op`) |
| `fill_stack.c`, `new_node.c` | Argument validation and stack construction |
| `stack_swap.c`, `stack_push.c`, `stack_rotate.c`, `stack_reverse_rotate.c` | The 11 operations |
| `disorder.c` | Disorder metric |
| `selection_sort.c`, `chunk_based_sort.c`, `radix_sort.c` | The three base algorithms |
| `bench.c`, `ft_printf_stderr.c` | `--bench` report (written to `stderr`) |
| `checker.c` | Bonus checker |
| `libft/` | Our libft |
 
Both stacks are circular linked lists, so `ra`, `rra`, `rb`, `rrb` are constant-time pointer
moves, and every node carries its `value` and its `rank` (position in the sorted order).
All state (stacks, operation counters, mode, disorder) lives in one `t_data` structure in
`main`; there are no global variables.
 
## Instructions
 
### Build
 
```sh
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```
 
The Makefile uses `cc -Wall -Wextra -Werror` and does not relink when nothing changed.
 
### Usage
 
```sh
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <integers...>
```
 
* The first integer is the top of stack `a`. Flags can come in any order but must come before the numbers.
* With no strategy flag, `--adaptive` is used.
* With no arguments the program prints nothing.
* On any error (non-integer, value outside the `int` range, duplicate, unknown flag) it prints `Error` followed by a newline on `stderr`.
* Operations are written on `stdout`, one per line.
```sh
$ ./push_swap 2 1 3 6 5 8
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK
$ ./push_swap --adaptive 0 one 2 3
Error
```
 
### Benchmark mode
 
`--bench` prints to `stderr` (the operation list still goes to `stdout`):
 
```sh
$ ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
OK
$ cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 0 rb: 2 rr: 0 rra: 0 rrb: 1 rrr: 0
```
 
For `--adaptive` the complexity shown is the one of the method that was actually selected.
 
### Bonus: checker
 
```sh
./checker <integers...>      # reads operations from stdin, one per line
```
 
It prints `OK` if stack `a` ends sorted and `b` empty, `KO` otherwise, and `Error` on `stderr`
for invalid arguments or an unknown / badly formatted instruction.
 
## Algorithms: explanation and justification
 
### Common building blocks
 
**Ranks.** Before the chunk and radix sorts, every value is replaced by its rank (`0 … n-1`) with
`assign_rank`. Working on ranks makes the values dense, so bit tests and range tests are exact.
Computing ranks costs CPU time but **zero** push_swap operations.
 
**Disorder metric.** `compute_disorder` counts the pairs `(i, j)` with `i < j` and `a[i] > a[j]`
("mistakes") and divides by the total number of pairs, giving a value in `[0, 1]`: 0 for a sorted
stack, 1 for a reversed one, about 0.5 for a random permutation. It is computed once, **before any
move**, and uses O(1) extra space. If the stack is already sorted nothing is printed.
 
**Space.** Every strategy only moves nodes between the two stacks: O(n) total for the nodes (one
`rank` per node), O(1) auxiliary space on top of that.
 
### 1. Simple: selection sort (O(n²))
 
*How it works.* Repeat until `a` is empty: find the minimum of `a`, bring it to the top with the
shorter of `ra` / `rra`, and `pb` it. At the end `pa` everything back; since the minima were pushed in
increasing order, `a` ends up sorted.
 
*Cost.* With `m` elements left, bringing the minimum to the top costs at most `⌊m/2⌋` rotations and
one `pb`. The total is at most `Σ (⌊m/2⌋ + 1) + n ≈ n²/4 + 2n = O(n²)`.
When the input is nearly sorted the minimum is always near the top, so the cost falls to about `2n`
(n `pb` + n `pa`).
 
*Why it was chosen.* It is the simplest correct baseline and, as the measurements below show, it is
the cheapest method for very low disorder.
 
### 2. Medium: chunk-based sort (O(n√n))
 
*How it works.*
1. **Push phase.** Keep a counter `sent` (elements already pushed) and a window of width `w`.
   Look at the top of `a` with rank `r`:
   * `r <= sent`: `pb`, then `rb` (the smallest values go to the bottom of `b`);
   * `r <= sent + w`: `pb` (stays on top of `b`);
   * otherwise `ra` (skip it for now).
2. **Pull-back phase.** While `b` is not empty: find the maximum rank in `b`, rotate `b` the short way
   (`rb` or `rrb`) until it is on top, and `pa`. Larger values are moved first, so `a` is built
   in ascending order.
The window width is `w = 5` for `n ≤ 20`, `15` for `n ≤ 100`, `35` for `n ≤ 500`, and about
`c·√n` beyond that. <!-- TODO: chunk_width() currently returns n / 12 + 1 for n > 500; change it to a
width proportional to the square root of n (integer square root, no math.h) so this sentence and the
complexity claim below are true for large inputs. -->
 
*Cost.*
* Push phase: every element is pushed exactly once. A full sweep of `a` costs at most `n` `ra`, and
  during one sweep every element still in `a` that belongs to the current window gets pushed, so each
  sweep pushes at least `w + 1` elements. There are at most `⌈n/(w+1)⌉` sweeps, so the rotations
  are at most `n · ⌈n/(w+1)⌉ = O(n²/w)`.
* Pull-back phase: `b` is almost sorted (large values near the top, small ones near the bottom), so
  the maximum is within `O(w)` positions of an end. Each extraction costs `O(w)` rotations plus one
  `pa`, giving `O(n·w)`.
* Total: `O(n²/w + n·w)`, which is minimised for `w = Θ(√n)` and gives **O(n√n)**.
  In our simulations the largest single rotation in the pull-back phase was always below `w`
  (for example 24 for `n = 500`, `w = 35`).
*Why it was chosen.* It is a classic way to reach the O(n√n) class with only two stacks, and in practice it
gave the lowest operation counts of the three base algorithms for `n = 100` and `n = 500`.
 
### 3. Complex: LSD radix sort (O(n log n))
 
*How it works.* On the ranks `0 … n-1`, repeat for each bit from the least significant one:
scan `a` once, `pb` every element whose current bit is 0 and `ra` every element whose bit is 1;
then `pa` everything back from `b`. Because each pass is stable, after the last bit the stack is sorted.
The number of passes is `⌈log₂ n⌉` (computed from the largest rank, `n - 1`).
 
*Cost.* Each pass uses `n` operations for the scan (`pb` or `ra`) plus at most `n` `pa`, so at most `2n`
operations per pass and at most `2n⌈log₂ n⌉ = O(n log n)` in total. With balanced bits it is about
`1.5 n ⌈log₂ n⌉`: for 500 numbers we measured 6784 operations (2284 `pb`, 2284 `pa`, 2216 `ra`,
9 passes).
 
*Why it was chosen.* It is simple, deterministic and its cost does not depend on the input order, which
makes the O(n log n) bound easy to defend. The price is that it never uses `rb`, `rr`, `ss`, etc.,
so a large share of its operations (the `pa` phase) only moves elements back.
 
### 4. Adaptive strategy
 
*Rule.* Compute the disorder once, before any move, then:
 
| Disorder | Method | Class |
|---|---|---|
| `< 0.2` (low) | selection sort | O(n²) |
| `0.2 ≤ d < 0.5` (medium) | chunk sort | O(n√n) |
| `≥ 0.5` (high) | radix sort | O(n log n) |
 
*Rationale for the thresholds.*
* 0.2 and 0.5 are the regime boundaries of the subject. A random permutation has a disorder close to
  0.5 and a reversed one has 1, so the "high" regime corresponds to unstructured or reversed data, where a
  method whose cost does not depend on the order (radix) is the safe, provably O(n log n) choice.
* For very low disorder the minimum is almost always near the top of `a`, so selection sort needs
  only about `2n` operations (see the measurements).
* The medium regime uses the chunk sort, whose cost is far below O(n²) once the input is clearly unsorted.
*Complexity argument (upper bounds in push_swap operations).* The adaptive strategy runs exactly one of the
three methods, plus the disorder computation, which produces no operation. Its cost is therefore
bounded by the bound of the selected method in each regime: O(n²) for `d < 0.2`, O(n√n) for
`0.2 ≤ d < 0.5` and O(n log n) for `d ≥ 0.5`. Space is O(n) for the nodes and O(1) auxiliary.
 
*Measured behaviour and known limitation.* On random inputs the disorder is about 0.5, which is exactly the
threshold between the medium and the high regime, so `--adaptive` behaves sometimes like the chunk sort
(about 580 operations for 100 numbers, about 5000 for 500) and sometimes like the radix sort (1084 and
6784). The averages over many runs are in between (see below). In our measurements the radix sort was
never the cheapest method at the tested sizes; it is used in the high regime because that regime requires an
O(n log n) method.

## Testing
 
* Randomised runs (all modes, with and without `--bench`, 1 to 500 numbers, negative values included)
  validated by both `checker_linux` and our `checker`.
* The operation counters printed by `--bench` were compared with the real number of each operation in the
  output stream.
* Error cases: non-integers, duplicates, values outside the `int` range, unknown flags, bad checker
  instructions.
* Memory: `valgrind --leak-check=full --show-leak-kinds=all` and AddressSanitizer report no error and no leak on
  normal runs and on every error path.

## Resources
 
* Donald E. Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching* (radix and selection sort).
* Cormen, Leiserson, Rivest, Stein, *Introduction to Algorithms* (radix sort, asymptotic notation).
* Wikipedia: *Radix sort*, *Selection sort*, *Bucket sort*, *Big O notation*, *Inversion (discrete mathematics)*.
* The 42 push_swap subject and the provided `checker_linux`.
### Use of AI
 
<!-- Confirm and edit this paragraph so it is exactly true for your project. -->
An AI assistant (Claude) was used for: compiling and testing the project (randomised runs, comparison
with `checker_linux`, and sanitizer runs), reviewing the code and pointing out bugs and Norm issues, explaining complexity and the structure of the benchmark, and drafting the text of this README.
The algorithms and the C code were written by the learners moaks and mmiklovi, and every AI suggestion was checked and tested before use.