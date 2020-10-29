/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:09:03 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/12 19:34:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printable_char(char c)
{
	int ret;

	ret = 0;
	if (c >= ' ' && c <= '~')
	{
		ret = 1;
	}
	return (ret);
}

int	ft_str_is_printable(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (ft_printable_char(str[i]) == 0)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
