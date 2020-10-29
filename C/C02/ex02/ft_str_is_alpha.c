/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:17:15 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/13 16:46:25 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_letter(char c)
{
	int ret;

	ret = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		ret = 1;
	}
	return (ret);
}

int	ft_str_is_alpha(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (ft_char_is_letter(str[i]) == 0)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
