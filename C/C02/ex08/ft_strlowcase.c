/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:56:34 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/12 19:58:56 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
