/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 06:39:54 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/08/21 06:39:57 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	p;

	p = 'a';
	while (p <= 'z')
	{
		ft_putchar (p);
		p++;
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
}
*/
