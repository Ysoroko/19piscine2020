/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:24:17 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/15 13:26:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j - 1] && str[i + j - 1] != 0
				&& to_find[j] != 0)
		{
			j++;
		}
		if (to_find[j] == 0 && j != 0)
		{
			return (&(str[i - 1]));
		}
		i++;
	}
	return (0);
}
