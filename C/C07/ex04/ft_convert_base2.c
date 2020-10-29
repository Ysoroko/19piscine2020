/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:19:30 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/23 17:56:25 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_count = -1;

int		ft_atoi_base(char *str, char *base);
int		pos_in_base(char c, char *base);
int		ft_strlength(char *str);
int		ft_samechar(char *base);
int		error(char *base);

void	ft_putnbr_base(unsigned int nbr, char *base, char *str)
{
	unsigned int n;

	n = nbr;
	if (error(base) == 1)
	{
	}
	else
	{
		if (n >= (unsigned int)ft_strlength(base))
		{
			ft_putnbr_base(n / ft_strlength(base), base, str);
			ft_putnbr_base(n % ft_strlength(base), base, str);
		}
		else
		{
			str[++g_count] = base[n];
		}
	}
}

int		ft_count_mem(long m, char *base_to)
{
	int mem_length;

	mem_length = 0;
	while (m / ft_strlength(base_to) != 0)
	{
		m = m / ft_strlength(base_to);
		mem_length++;
	}
	return (mem_length);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	int		m;
	int		mem_length;
	char	*str;

	n = ft_atoi_base(nbr, base_from);
	m = n;
	mem_length = 0;
	if (error(base_from) == 1 || error(base_to) == 1)
		return (0);
	if (m < 0)
		mem_length++;
	mem_length = ft_count_mem(m, base_to);
	str = malloc(sizeof(char) * (mem_length + 2));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		g_count++;
	}
	ft_putnbr_base(n, base_to, str);
	str[++g_count] = '\0';
	g_count = -1;
	return (str);
}
