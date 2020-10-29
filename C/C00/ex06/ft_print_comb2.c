/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:13:37 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/11 13:07:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_chars(char a, char b, char c, char d)
{
	int cond1;
	int cond2;
	int cond3;

	cond1 = (b == d) && (a < c);
	cond2 = (a == c) && (b < d);
	cond3 = ((a != c) && (b != d)) && (c > a);
	if (cond1 == 1 || cond2 == 1 || cond3 == 1)
	{
		if (((b <= '9') && (c <= ('9' + 1))) && ((d <= ('9' + 1))))
		{
			ft_putchar(a);
			ft_putchar(b);
			ft_putchar(' ');
			ft_putchar(c);
			ft_putchar(d);
			if ((a != '9') || (b != '8') || (c != '9') || (d != '9'))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

void	ft_while(char a, char b, char c, char d)
{
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				d = '0';
				while (d <= '9')
				{
					print_chars(a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	ft_while(a, b, c, d);
}
