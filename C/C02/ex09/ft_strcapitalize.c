/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:00:07 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/12 21:02:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_l_letter(char c)
{
	int ret;

	ret = 0;
	if (c >= 'a' && c <= 'z')
	{
		ret = 1;
	}
	return (ret);
}

int		ft_char_is_upkey_letter(char c)
{
	int ret;

	ret = 0;
	if (c >= 'A' && c <= 'Z')
	{
		ret = 1;
	}
	return (ret);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_upkey_letter(str[i]) == 1)
		{
			str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}
	return (str);
}

int		ft_char_is_l_or_n(char c)
{
	int ret;
	int cond1;
	int cond2;
	int cond3;

	ret = 0;
	cond1 = (c >= 'A' && c <= 'Z');
	cond2 = (c >= 'a' && c <= 'z');
	cond3 = (c >= '0' && c <= '9');
	if (cond1 || cond2 || cond3)
	{
		ret = 1;
	}
	return (ret);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	ft_strlowcase(str);
	if (ft_is_l_letter(str[0]))
	{
		str[0] = str[0] - ('a' - 'A');
	}
	while (str[i] != '\0')
	{
		if (!(ft_char_is_l_or_n(str[i - 1])) && (ft_is_l_letter(str[i])))
		{
			str[i] = str[i] - ('a' - 'A');
		}
		i++;
	}
	return (str);
}
