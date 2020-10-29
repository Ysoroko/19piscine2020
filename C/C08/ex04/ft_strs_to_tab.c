/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:43:49 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/24 10:34:20 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int					ft_strlength(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strdup(char *src)
{
	char *str;

	str = malloc(sizeof(*str) * ft_strlength(src) + 1);
	if (str == 0)
	{
		return (0);
	}
	return (ft_strcpy(str, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	int					j;
	struct s_stock_str	*pnt;

	i = 0;
	j = 0;
	pnt = malloc(sizeof(*pnt) * (ac + 1));
	if (pnt == 0)
	{
		return (0);
	}
	while (i < ac)
	{
		pnt[i].size = ft_strlength(av[i]);
		pnt[i].str = av[i];
		pnt[i].copy = ft_strdup(av[i]);
		i++;
	}
	pnt[i].size = 0;
	pnt[i].str = 0;
	pnt[i].copy = 0;
	return (pnt);
}
