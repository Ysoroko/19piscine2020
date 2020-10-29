/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:57:27 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/14 19:59:24 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_number(char c)
{
	int ret;

	ret = 0;
	if (c >= '0' && c <= '9')
	{
		ret = 1;
	}
	return (ret);
}

int	ft_str_is_numeric(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (ft_char_is_number(str[i]) == 0)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
