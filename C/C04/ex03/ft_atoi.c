/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:55:01 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/15 17:55:11 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_isspace(char c)
{
	char	tab[6];
	int		i;

	tab[0] = ' ';
	tab[1] = '\n';
	tab[2] = '\t';
	tab[3] = '\v';
	tab[4] = '\f';
	tab[5] = '\r';
	i = 0;
	while (i < 6)
	{
		if (c == tab[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		sign(int nbr)
{
	if (nbr % 2 == 0)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int		ft_atoi(char *str)
{
	int i;
	int sign_n;
	int sign_count;
	int number;

	i = 0;
	sign_n = 1;
	sign_count = 0;
	number = 0;
	while (my_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign_count++;
		i++;
	}
	sign_n = sign(sign_count);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (sign_n * number);
}
