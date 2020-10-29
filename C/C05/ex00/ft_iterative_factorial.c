/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:29:17 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/16 19:37:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int ret;
	int i;

	ret = nb;
	i = 1;
	if (nb == 0)
	{
		return (1);
	}
	else if (nb < 0)
	{
		return (0);
	}
	while (nb - i > 1)
	{
		ret = ret * (nb - i);
		i++;
	}
	return (ret);
}
