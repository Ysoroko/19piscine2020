/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:34:39 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/12 19:58:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_lowkey_letter(char c)
{
	int ret;

	ret = 0;
	if (c >= 'a' && c <= 'z')
	{
		ret = 1;
	}
	return (ret);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_lowkey_letter(str[i]) == 1)
		{
			str[i] = str[i] - ('a' - 'A');
		}
		i++;
	}
	return (str);
}
