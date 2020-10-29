/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:05:28 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/13 16:47:41 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_upkey_letter(char c)
{
	int ret;

	ret = 0;
	if (c >= 'A' && c <= 'Z')
	{
		ret = 1;
	}
	return (ret);
}

int	ft_str_is_uppercase(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (ft_char_is_upkey_letter(str[i]) == 0)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
