/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:19:30 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/21 21:50:02 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
				|| base[i] == '\n' || base[i] == '\t' ||
				base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		pos_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (error(base) == 1)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (pos_in_base(str[i], base) != -1)
	{
		nbr = nbr * ft_strlength(base);
		nbr = nbr + pos_in_base(str[i], base);
		i++;
	}
	return (sign * nbr);
}
