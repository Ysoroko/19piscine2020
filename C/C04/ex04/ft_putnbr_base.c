/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:32:36 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/21 12:27:52 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlength(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_samechar(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		error(char *base)
{
	int i;

	if (ft_strlength(base) <= 1)
	{
		return (1);
	}
	if (ft_samechar(base) == 1)
	{
		return (1);
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long n;

	n = (long)nbr;
	if (error(base) == 1)
	{
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= ft_strlength(base))
		{
			ft_putnbr_base(n / ft_strlength(base), base);
			ft_putnbr_base(n % ft_strlength(base), base);
		}
		else
		{
			ft_putchar(base[n]);
		}
	}
}
