/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:32:21 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/14 18:26:22 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_str_length(char str[])
{
	unsigned int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int src_length;

	src_length = ft_str_length(src);
	if (size == 0)
	{
		return (src_length);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}
