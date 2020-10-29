/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:54:45 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/20 13:13:36 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int n;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(n) * (max - min));
	if (*range == 0)
	{
		*range = 0;
		return (-1);
	}
	n = min;
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = n;
		n++;
		i++;
	}
	return (max - min);
}
