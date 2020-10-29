/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:07:32 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/29 12:15:55 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int		ft_invalid_operator(char c)
{
	int		i;
	char	*str;

	str = "+-*/%";
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_main_errors(int argc, char **argv)
{
	if (argc != 4)
	{
		return (1);
	}
	if (ft_strlength(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (1);
	}
	if (ft_invalid_operator(argv[2][0]) == 1)
	{
		ft_putstr("0\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (ft_main_errors(argc, argv) == 1)
	{
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		ft_plus(a, b);
	else if (argv[2][0] == '-')
		ft_minus(a, b);
	else if (argv[2][0] == '*')
		ft_multiply(a, b);
	else if (argv[2][0] == '/')
		ft_divide(a, b);
	else if (argv[2][0] == '%')
		ft_modulo(a, b);
	return (0);
}
