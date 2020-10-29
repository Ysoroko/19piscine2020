/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/19 11:43:11 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *pnt;
	int n;

	if (min >= max)
	{
		return (0);
	}
	pnt = malloc(sizeof(n) * (max - min));
	if (pnt == 0)
	{
		return (0);
	}
	n = min;
	i = 0;
	while (i < max - min)
	{
		pnt[i] = n;
		n++;
		i++;
	}
	return (pnt);
}
