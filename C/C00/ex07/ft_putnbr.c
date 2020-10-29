/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:43:03 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/18 11:15:59 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		abs(int n)
{
	if (n < 0)
	{
		return (-1 * n);
	}
	else
	{
		return (n);
	}
}

int		div(int n)
{
	int d;
	int count;

	d = abs(n);
	count = 1;
	if (d >= 1000000000)
	{
		return (1000000000);
	}
	while (d > 0)
	{
		d = d / 10;
		count = count * 10;
	}
	count = count / 10;
	return (count);
}

void	ft_putnbr(int n)
{
	int d;
	int c;

	c = abs(n);
	if (n == 0)
	{
		write(1, "0", 1);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		c = -n;
		ft_putchar('-');
	}
	d = div(c);
	while (d >= 1)
	{
		ft_putchar('0' + c / d);
		c = c % d;
		d = d / 10;
	}
}
