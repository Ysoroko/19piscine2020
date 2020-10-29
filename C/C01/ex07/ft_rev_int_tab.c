/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:12:20 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/12 14:28:19 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int first;
	int last;
	int i;
	int middle;

	i = 0;
	middle = size / 2;
	if (size > 0)
	{
		while (i < middle)
		{
			first = tab[i];
			last = tab[size - i - 1];
			tab[i] = last;
			tab[size - i - 1] = first;
			i++;
		}
	}
}
