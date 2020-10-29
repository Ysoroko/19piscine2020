/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:10:13 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/25 22:59:41 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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

/*Pour ecrire le string tant qu'il est le meme*/
int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && !(s1[i] == '\0' || s2[i] == '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* This function copies the entire dictionary in a string
 * and returns the string */
# define BUF_SIZE 4096
char	*ft_dict_to_str(char *str)
{
	char *buf;
	int rd;
	int fd;

	buf = malloc(BUF_SIZE + 1);
	fd = open(str, O_RDONLY);
	if (fd == -1) 
    { 
        ft_putstr("Error\n"); 
		return (0);
    }
	else
	{
		rd = read(fd, buf, BUF_SIZE);
		buf[rd] = '\0';
	//	ft_putstr(buf); //prints the buff, delete this after!
		if (close(fd) == -1)
		{
			ft_putstr("Error\n");
		}
	}	
	return (buf);
}	

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f' || c == ' ')
	{
		return (1);
	}
	else
	{ 
		return (0);
	}
}

int ft_previous_three_are_zero(char *str, int i)
{
	int j;

	j = 0;
	if (i == ft_strlen(str) - 1)
	{
		return (1);
	}
	if (i == 0)
		return (0);
	while (j < 3)
	{
		if (str[i - j] != '0')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int		ft_only_zeroes_left(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_char_is_number(char c)
{
	int ret;

	ret = 0;
	if (c >= '0' && c <= '9')
	{
		ret = 1;
	}
	return (ret);
}

int	ft_issd(char c)
{
	if(ft_isspace(c) == 1 || c == ':')
		return (1);
	return (0);
}

/* Pour trouver le char a la position i dans le dictionnaire*/
char	*ft_str_c(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (i == 0)
				return (&str[i]);
			else if (i > 0 && i < ft_strlen(str) - 1)
				if (str[i - 1] == '\n' && (ft_issd(str[i + 1])))
					return (&str[i]);
		}
		i++;
	}
	return (0);
}

/* Pour trouver des chiffres au-dela de 10*/
char	*ft_str_str(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[++i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j - 1] && str[i + j - 1] != 0
				&& to_find[j] != 0)
			j++;
		if (to_find[j] == 0 && j != 0)
		{
			if (i > 2 && i < ft_strlen(str) - 1)
			{
				if (str[i - 2] == '\n' && (ft_issd(str[i + j])))
						return (&(str[i - 1]));
			}
			else if (i <= 2)
				if (ft_issd(str[i + j]))
					return (&(str[i - 1]));
		}
	}
	return (0);
}


/* Pour extraire le mot lie au nombre de la ligne correspondante*/
void ft_extract_and_print_words(char *str, int j, int length, char *nmb)
{
	int i;
	
	i = 0;
	while (ft_char_is_number(str[i]) == 1)
		i++; 
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == ':')
		i++;
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] != '\n')
	{
		ft_putchar(str[i]);
		i++;
	}
	if (j != length - 1)
	{
		if (!(ft_only_zeroes_left(nmb, j + 1) && j > 0))
			ft_putchar(' ');
	}
}

/*Pour extraire "billion, million etc" en fonction de la position dans nbr*/
char *power_to_str(int power, char first, char fill)
{
	int i;
	char *str;

	str = malloc(sizeof(*str) * (power + 2));
	if (str == 0)
	{
		return (0);
	}
	str[0] = first;
	i = 1;
	while (i <= power)
	{
		str[i] = fill;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* Pour determiner si le chiffre a la position est un multiple de 10*/
int is_tens(int i, int nmb_len)
{
	int x;

	x = 1;
	while (nmb_len - 2 - (x * 3) > -3)
	{
		if (nmb_len - 2 - (x * 3) == i || nmb_len - 2 == i)
		{
			return (1);
		}
		x++;
	}
	return (0);
}

//TOUT CE QUI SUIT DIVISE FT_PRINT_FROM_DICT

void ft_case_zero(char *number, char *dict_saved)
{
	char *ptr;
	ptr = ft_str_c(number[0], dict_saved);
	ft_extract_and_print_words(ptr, 0, ft_strlen(number), number);
}		

void ft_case_hundred(char *number, int i, char *dict_saved)
{
	int nmb_len;
	char *ptr;

	nmb_len = ft_strlen(number);
	if (number[i] != '0')
	{
		ptr = ft_str_c(number[i], dict_saved);	
		ft_extract_and_print_words(ptr, i, nmb_len, number);
		ptr = ft_str_str(dict_saved, "100");
		ft_extract_and_print_words(ptr, i, nmb_len, number);
	}
}

int ft_case_thousand(char *number, int i, char *dict_saved, int printed)
{
	int nmb_len;
	char *ptr;
	char *power;

	nmb_len = ft_strlen(number);
	if (number[i] != '0' && printed == 0)
	{
		ptr = ft_str_c(number[i], dict_saved);
		ft_extract_and_print_words(ptr, i, nmb_len, number);
	}
	if(ft_previous_three_are_zero(number, i) == 0)
	{	
		power = power_to_str(nmb_len - i - 1, '1', '0');
		ptr = ft_str_str(dict_saved, power);
		ft_extract_and_print_words(ptr, i, nmb_len, number);
		free(power);
	}
	return (0);
}

int ft_case_twenties(char *number, int i, char *dict_saved, int printed)
{
	char *ptr;
	char *power;
	int nmb_len;

	nmb_len = ft_strlen(number);
	if (number[i] != '0' && printed == 0)
	{
		power = power_to_str(1, number[i], '0');
		ptr = ft_str_str(dict_saved, power);
		ft_extract_and_print_words(ptr, i, nmb_len, number);
		free(power);	
	}
	return (0);
}

int ft_case_eleven(char *number, int i, char *dict_saved)
{
	char *ptr;
	char *power;
	int nmb_len;

	nmb_len = ft_strlen(number);
	power = power_to_str(1, number[i], number[i+1]);
	ptr = ft_str_str(dict_saved, power);
	if (i == nmb_len - 2)
		ft_extract_and_print_words(ptr, i + 1, nmb_len, number);	
	else
		ft_extract_and_print_words(ptr, i, nmb_len, number);
	free(power);
	return (1);
}

void ft_case_else(char *number, int i, char *dict_saved)
{
	char *ptr;
	int nmb_len;

	nmb_len = ft_strlen(number);
	if (number[i] != '0' && number[i-1] != '1')
	{		
		ptr = ft_str_c(number[i], dict_saved);
		ft_extract_and_print_words(ptr, i, nmb_len, number);
	}
}

void ft_while(char *nb, char *dict_saved)
{
	int i;
	int l;
	int printed;

	i = -1;
	printed = 0;
	l = ft_strlen(nb);
	while (nb[++i] != '\0')
	{
		if ((l - i) % 3 == 0)
			ft_case_hundred(nb, i, dict_saved);
		else if ((l - i - 1) % 3 == 0 && i != l - 1)	
			printed = ft_case_thousand(nb, i, dict_saved, printed);
		else if ((is_tens(i, l) == 1 || (l == 2 && i == 0)) && nb[i] != '1')
			printed = ft_case_twenties(nb, i, dict_saved, printed);
		else if ((is_tens(i, l) == 1 || (l == 2 && i == 0)) && nb[i] == '1')
			printed = ft_case_eleven(nb, i, dict_saved);
		else
			ft_case_else(nb, i, dict_saved);
	}
}

void ft_print_from_dict(char *dict, char *nb)
{
	char *dict_saved;
	
	dict_saved = ft_dict_to_str(dict);;
	if (nb[0] == '0' && nb[1] == '\0')
		ft_case_zero(nb, dict_saved);
	else
	{
		ft_while(nb, dict_saved);	
	}
	ft_putchar('\n');
	free(dict_saved);
}

int    ft_error(char *str)
{
    int i;
    i = 0;
    if (str[0] == '0' && str[1] != '\0')
        return (1);
	while (str[i] != '\0')
	{
    	if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*pour executer, ecrire le nom du dictionnaire en tant que 1er argument*/
int		main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		if (ft_error(argv[1]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_print_from_dict("dict",argv[1]);
		return (0);
	}
	if (argc == 3)
	{
		if (ft_error(argv[2]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_print_from_dict(argv[1],argv[2]);
		return (0);
	}
}
