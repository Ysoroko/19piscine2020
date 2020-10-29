/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:19:52 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/27 20:02:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		char_not_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_wordcount(char *str, char *sep)
{
	int i;
	int count;

	i = 1;
	count = 0;
	if (char_not_sep(str[0], sep))
		count++;
	while (str[i] != '\0')
	{
		if (char_not_sep(str[i], sep) && !(char_not_sep(str[i - 1], sep)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_malloc(char *str, char *sep)
{
	int		len;
	char	**tab_str;

	len = ft_wordcount(str, sep) + 4;
	tab_str = malloc(sizeof(*tab_str) * (len));
	if (tab_str == 0)
	{
		return (0);
	}
	return (tab_str);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		s;
	int		i;
	int		j;
	char	**tab_str;

	s = 0;
	i = 0;
	j = 0;
	tab_str = ft_malloc(str, charset);
	while (i < ft_wordcount(str, charset))
	{
		j = 0;
		tab_str[i] = malloc(ft_strlen(str) + 1);
		if (tab_str == 0)
			return (0);
		while (str[s] && !char_not_sep(str[s], charset))
			s++;
		while (str[s] != '\0' && char_not_sep(str[s], charset))
			tab_str[i][j++] = str[s++];
		tab_str[i][j] = '\0';
		i++;
	}
	tab_str[i] = 0;
	return (tab_str);
}
