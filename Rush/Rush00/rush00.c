/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:24:01 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/10 16:10:13 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		ft_main();

void	print_first(int x)
{
	int i;

	i = 2;
	ft_putchar('o');
	if (x > 1)
	{
		while (i < x)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	print_middle(int x, int y)
{
	int j;
	
	j = 2;
	ft_putchar('|');
	if (x > 1)
	{
		while (j < y - 1)
		{
			ft_putchar(' ');
			j++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	char coin;
	char vligne;
	char hligne;
	char empty;
	int i;

	coin = 'o';
	hligne = '-';
	vligne = '|';
	empty = ' ';
	i = 1;
	print_first(x);
	if (y > 1)
	{
		while (i < (y - 1))
		{
			print_middle(x,y);
			i++;
		}
		print_first(x);
	}
}
