/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:15:35 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/28 12:22:45 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *ret_tab;

	i = 0;
	ret_tab = malloc(sizeof(int) * length);
	if (ret_tab == 0)
		return (ret_tab);
	while (i < length)
	{
		ret_tab[i] = f(tab[i]);
		i++;
	}
	return (ret_tab);
}
