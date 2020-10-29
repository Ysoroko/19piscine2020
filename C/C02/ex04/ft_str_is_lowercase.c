/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:01:33 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/13 16:47:31 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowkey_letter(char c)
{
	int ret;

	ret = 0;
	if (c >= 'a' && c <= 'z')
	{
		ret = 1;
	}
	return (ret);
}

int	ft_str_is_lowercase(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (ft_char_is_lowkey_letter(str[i]) == 0)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
