/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:35:27 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/26 10:53:44 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long n;

	n = (long)nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_base(n / 10, base);
		ft_putnbr_base(n % 10, base);
	}
	else
	{
		ft_putchar(base[n]);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	if (par == 0)
	{
	}
	else
	{
		while (par[i].str != 0)
		{
			ft_putstr(par[i].str);
			ft_putchar('\n');
			ft_putnbr_base(par[i].size, "0123456789");
			ft_putchar('\n');
			if (par[i].copy != 0)
			{
				ft_putstr(par[i].copy);
				ft_putchar('\n');
			}
			i++;
		}
	}
}
