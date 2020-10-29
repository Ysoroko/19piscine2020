/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:01:40 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/29 11:44:27 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_plus(int a, int b);
void	ft_minus(int a, int b);
void	ft_multiply(int a, int b);
void	ft_divide(int a, int b);
void	ft_modulo(int a, int b);

void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_strlength(char *str);

int		abs(int n);
int		div (int n);
void	ft_putnbr(int n);

int		my_isspace(char c);
int		sign(int nbr);
int		ft_atoi(char *str);

#endif
