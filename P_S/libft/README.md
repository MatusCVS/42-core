*This project has been created as part of the 42 curriculum by moaks.*

# Libft

## Description

Libft is a custom C library built from scratch as the very first project of the 42
core curriculum. Its goal is to make you reimplement the most commonly used
functions of the standard C library (`libc`), understand exactly how they work
under the hood, and extend them with a set of additional utility functions that
the `libc` doesn't provide. The resulting `libft.a` static library becomes a
personal toolbox that can be reused in every future C project of the curriculum.

The library is split into three parts:

- **Part 1 - Libc functions**: reimplementations of standard functions
  (`isalpha`, `strlen`, `memcpy`, `strncmp`, `atoi`, `calloc`, `strdup`, etc.)
  prefixed with `ft_`.
- **Part 2 - Additional functions**: extra string/array utilities not found in
  the `libc` (`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`,
  `ft_strmapi`, `ft_striteri`, and the `ft_put*_fd` output helpers).
- **Part 3 - Linked list**: a minimal singly linked list (`t_list`) along with
  a full set of functions to create, add, iterate, map, and free nodes.

## Instructions

### Compilation

Clone the repository, then simply run `make` at the root:

```bash
git clone <repo-url> libft
cd libft
make
```

This compiles every `.c` file with `-Wall -Wextra -Werror` and archives the
resulting object files into `libft.a` using `ar`.

Available Makefile rules:

| Rule     | Effect                                             |
|----------|-----------------------------------------------------|
| `all`    | Compiles the library (default rule)                |
| `clean`  | Removes the object files                           |
| `fclean` | Removes the object files and `libft.a`             |
| `re`     | Runs `fclean` then `all`                           |

### Using the library in another project

Include the header and link against the archive when compiling your project:

```bash
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror your_files.c -L. -lft -o your_program
```

or add `libft.a` directly to your project's own Makefile (copy the `libft`
sources into a `libft/` folder, build the library through its own Makefile,
then link it against your program).

## Library overview

### Part 1 - Libc functions

| Function       | Description                                            |
|----------------|----------------------------------------------------------|
| `ft_isalpha`   | Checks for an alphabetic character                       |
| `ft_isdigit`   | Checks for a digit (0-9)                                  |
| `ft_isalnum`   | Checks for an alphanumeric character                      |
| `ft_isascii`   | Checks for an ASCII character                              |
| `ft_isprint`   | Checks for a printable character                          |
| `ft_strlen`    | Returns the length of a string                             |
| `ft_memset`    | Fills memory with a constant byte                          |
| `ft_bzero`     | Zeroes out a memory area                                    |
| `ft_memcpy`    | Copies memory area                                          |
| `ft_memmove`   | Copies memory area, handling overlap                        |
| `ft_strlcpy`   | Copies a string into a fixed-size buffer                    |
| `ft_strlcat`   | Concatenates a string into a fixed-size buffer               |
| `ft_toupper`   | Converts a character to uppercase                             |
| `ft_tolower`   | Converts a character to lowercase                              |
| `ft_strchr`    | Locates the first occurrence of a character in a string        |
| `ft_strrchr`   | Locates the last occurrence of a character in a string           |
| `ft_strncmp`   | Compares two strings, up to n bytes                                |
| `ft_memchr`    | Locates a byte in memory                                            |
| `ft_memcmp`    | Compares two memory areas                                             |
| `ft_strnstr`   | Locates a substring, bounded search                                    |
| `ft_atoi`      | Converts a string to an integer                                          |
| `ft_calloc`    | Allocates and zero-initializes memory                                      |
| `ft_strdup`    | Duplicates a string                                                          |

### Part 2 - Additional functions

| Function        | Description                                                        |
|-----------------|----------------------------------------------------------------------|
| `ft_substr`     | Allocates and returns a substring of a given string                    |
| `ft_strjoin`    | Allocates and returns the concatenation of two strings                   |
| `ft_strtrim`    | Trims leading/trailing characters of a set from a string                   |
| `ft_split`      | Splits a string into an array of strings using a delimiter                   |
| `ft_itoa`       | Converts an integer to a newly allocated string                                |
| `ft_strmapi`    | Applies a function to each character of a string, returns a new string           |
| `ft_striteri`   | Applies a function to each character of a string, in place                         |
| `ft_putchar_fd` | Outputs a character to the given file descriptor                                     |
| `ft_putstr_fd`  | Outputs a string to the given file descriptor                                          |
| `ft_putendl_fd` | Outputs a string followed by a newline to the given file descriptor                      |
| `ft_putnbr_fd`  | Outputs an integer to the given file descriptor                                            |

### Part 3 - Linked list

The `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function          | Description                                                          |
|-------------------|------------------------------------------------------------------------|
| `ft_lstnew`       | Creates a new list node                                                   |
| `ft_lstadd_front` | Adds a node at the beginning of the list                                     |
| `ft_lstsize`      | Counts the number of nodes in the list                                        |
| `ft_lstlast`      | Returns the last node of the list                                               |
| `ft_lstadd_back`  | Adds a node at the end of the list                                                |
| `ft_lstdelone`    | Frees a node's content and the node itself                                          |
| `ft_lstclear`     | Frees a node and all its successors                                                   |
| `ft_lstiter`      | Applies a function to the content of each node                                          |
| `ft_lstmap`       | Applies a function to each node's content and builds a new list                           |

## Resources

- [The Linux `man` pages](https://man7.org/linux/man-pages/) - reference for
  the exact prototypes and behavior of the original `libc` functions.

**AI usage**: An AI assistant (Claude) was used only to generate this
`README.md` file (formatting the description, instructions, function tables,
and resources) from the project's source files and the subject PDF. No AI was
used to write, debug, or review the C source code itself, in accordance with
the project's AI Instructions chapter.