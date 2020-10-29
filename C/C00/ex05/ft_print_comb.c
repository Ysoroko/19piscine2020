/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:24:50 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/11 13:01:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printchars(char a, char b, char c)
{
	if ((a != b) && (b != c) && (a != c))
	{
		if ((a < b) && (b < c))
		{
			ft_putchar(a);
			ft_putchar(b);
			ft_putchar(c);
			if ((a != '7') || (b != '8') || (c != '9'))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				ft_printchars(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
