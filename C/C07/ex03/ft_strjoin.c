/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:04:42 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/23 17:05:57 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int		ft_tablength(char **str, int size)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_write(int size, char **strs, char *sep, char *pnt)
{
	int		i;
	int		j;
	int		k;
	int		n;

	i = -1;
	n = -1;
	while (++i < size)
	{
		j = -1;
		k = -1;
		while (strs[i][++j] != '\0')
			pnt[++n] = strs[i][j];
		if (i != size - 1)
		{
			while (sep[++k] != '\0')
				pnt[++n] = sep[k];
		}
	}
	pnt[++n] = '\0';
	return (pnt);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*pnt;

	if (size == 0)
		return (malloc(sizeof(*pnt) * 1));
	pnt = malloc(sizeof(*pnt) * ((size - 1) * ft_strlength(sep)
				+ ft_tablength(strs, size) + 1));
	if (pnt == 0)
		return (0);
	pnt = ft_write(size, strs, sep, pnt);
	return (pnt);
}
