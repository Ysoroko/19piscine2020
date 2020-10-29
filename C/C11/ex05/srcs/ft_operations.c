/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:06:59 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/29 12:10:05 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_plus(int a, int b)
{
	ft_putnbr(a + b);
	ft_putchar('\n');
}

void	ft_minus(int a, int b)
{
	ft_putnbr(a - b);
	ft_putchar('\n');
}

void	ft_multiply(int a, int b)
{
	ft_putnbr(a * b);
	ft_putchar('\n');
}

void	ft_divide(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(a / b);
	ft_putchar('\n');
}

void	ft_modulo(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(a % b);
	ft_putchar('\n');
}
