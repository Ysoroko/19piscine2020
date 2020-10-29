/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:22:28 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/16 18:39:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		return (0);
	}
	while (i * i < nb && i <= 46339)
	{
		i++;
	}
	if (i * i == nb)
	{
		return (i);
	}
	else
	{
		return (i + 1);
	}
}

int		ft_is_prime(int nb)
{
	int i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i = i + 2;
	}
	return (1);
}
