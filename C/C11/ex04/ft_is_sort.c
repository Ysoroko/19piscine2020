/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:28:14 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/29 13:02:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sgn(int n)
{
	if (n < 0)
		return (-1);
	else if (n > 0)
		return (1);
	else
		return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int sign;

	i = 1;
	sign = sgn(f(tab[i - 1], tab[i]));
	while (i < length)
	{
		if (sgn(f(tab[i - 1], tab[i])) != sign)
		{
			if (sgn(f(tab[i - 1], tab[i])) != 0 && sign != 0)
				return (0);
		}
		i++;
	}
	return (1);
}
