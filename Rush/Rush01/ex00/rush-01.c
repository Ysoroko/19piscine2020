/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:58:04 by ysoroko           #+#    #+#             */
/*   Updated: 2020/10/18 18:34:53 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int *top_row(int col1up, int col2up, int col3up, int col4up)
{
	int tab[4];
	int *pnt;

	pnt = malloc(sizeof(*tab) * 4);
	tab[0] = col1up;
	tab[1] = col2up;
	tab[2] = col3up;
	tab[3] = col4up;

	return (pnt);
}

int *bottom_row(int col1down, int col2down, int col3down, int col4down)
{
	int tab[4];
	int *pnt;

	pnt = malloc(sizeof(*tab) * 4);
	tab[0] = col1down;
	tab[1] = col2down;
	tab[2] = col3down;
	tab[3] = col4down;

	return (pnt);
}

int *left_column(int row1left, int row2left, int row3left, int row4left)
{
	int tab[4];
	int *pnt;

	pnt = malloc(sizeof(*tab) * 4);
	tab[0] = row1left;
	tab[1] = row2left;
	tab[2] = row3left;
	tab[3] = row4left;

	return (pnt);
}

int *right_column(int row1right, int row2right, int row3right, int row4right)
{
	int tab[4];
	int *pnt;

	pnt = malloc(sizeof(*tab) * 4);
	tab[0] = row1right;
	tab[1] = row2right;
	tab[2] = row3right;
	tab[3] = row4right;

	return (pnt);
}


void ft_error(void)
{
	ft_putstr("Error");
}


int ft_tab(int col1up, int col2up, int col3up, int col4up, int col1down, int col2down, int col3down, int col4down, int row1left, int row2left, int row3left, int row4left, int row1right, int row2right, int row3right, int row4right)
{
	int tab[4][4];
	int i;
	int j;
	int n;
	int k;
	int l;
	int count;

	i = 0;
	j = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < 4)
	{
		if (top_row(col1up, col2up, col3up, col4up)[i] == 4)
		{
			while (j < 4)
			{
				tab[i][j] = n;
				n++;
				j++;
			}
			n = 1;
		}
        else if (top_row(col1up, col2up, col3up, col4up)[i] == 1)
        {
            if (tab[i][j] != 4)
            {
                ft_error();
                return (0);
            }
            tab[i][j] = 4;
        }
			else if (top_row(col1down, col2down, col3down, col4down)[i] == 2)
        {
			l = j;
			while (l < 4)
			{
				if(tab[i][l] == 4)
				{
					if (tab[i][j] != 3)
					{
						ft_error();
						return (0);
					}
					tab[i][j] = 3;
					break ;
				}
				l++;
			}
	   	}

		i++;
	}
	i = 0;
	j = 3;
	n = 1;
	k = 0;
	l = 0;
	while (i < 4)
	{
			if (bottom_row(col1down, col2down, col3down, col4down)[i] == 4)
		{
				if(tab[i][l] == 4)

			while (j >= 0)
			{	
				if (tab[i][j] != n)
				{
					ft_error();
					return (0);
				}
				tab[i][j] = n;
				n++;
				j--;
			}
			n = 1;
		}
        else if (bottom_row(col1down, col2down, col3down, col4down)[i] == 1)
        {
            if (tab[i][j] != 4)
            {
                ft_error();
                return (0);
            }
            tab[i][j] = 4;
        }
			else if (bottom_row(col1down, col2down, col3down, col4down)[i] == 2)
        {
			l = j;
			while (l > 0)
			{
				if(tab[i][l] == 4)
				{
					if (tab[i][j] != 3)
					{
						ft_error();
						return (0);
					}
					tab[i][j] = 3;
					break ;
				}
				l--;
			}
	   	}

		i++;
	}

	j = 0;
	i = 0;
	k = 0;
	l = 0;
	n = 1;

	while (j < 4)
	{
			if (left_column(row1left, row2left, row3left, row4left)[j] == 4)
		{
			while (i < 4)
			{
				if (tab[i][j] != n)
				{
					ft_error();
					return(0);
				}
				tab[i][j] = n;
				n++;
				i++;
			}
		}
        else if (left_column(row1left, row2left, row3left, row4left)[j] == 1)
        {
            if (tab[i][j] != 4)
            {
                ft_error();
                return (0);
            }
            tab[i][j] = 4;
        }
			else if (left_column(col1down, col2down, col3down, col4down)[i] == 2)
        {
			l = i;
			while (l < 4)
			{
				if(tab[l][j] == 4)
				{
					if (tab[i][j] != 3)
					{
						ft_error();
						return (0);
					}
					tab[i][j] = 3;
					break ;
				}
				l++;
			}
	   	}
		j++;
	}

	j = 0;
	i = 3;
	n = 1;

	while (j < 4)
	{
		if (right_column(row1right, row2right, row3right, row4right)[j] == 4)
		{
			while (i >= 0)
			{
				if (tab[i][j] != n)
				{
					ft_error();
					return (0);
				}
				tab[i][j] = n;
				n++;
				i--;
			}
		}
        else if (right_column(row1right, row2right, row3right, row4right)[j] == 1)
        {
            if (tab[i][j] != 4)
            {
                ft_error();
                return (0);
            }
            tab[i][j] = 4;
        }
		else if (left_column(col1down, col2down, col3down, col4down)[i] == 2)
        {
			l = i;
			while (l > 0)
			{
				if(tab[l][j] == 4)
				{
					if (tab[i][j] != 3)
					{
						ft_error();
						return (0);
					}
					tab[i][j] = 3;
					break ;
				}
				l--;
			}
	   	}
		j++;
	}

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	n = 0;
	
	while (i < 4)
	{
		j = 0;
		n = 0;
		k = 0;
		l = 0;
		while (j < 4)
		{
			if (tab[i][j] == 0)
			{
				count++;
				while (k < 4)
				{
					n += tab[k][j];
					k++;
				}
				if (n >= 6)
				{
					tab[i][j] = 10 - n;
				}
				n = 0;
				while (l < 4)
				{
					n += tab[i][l];
					l++;
				}
				if (n >= 6)
				{
					tab[i][j] = 10 - n;
				}
			}
		i++;
		}
	}

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}

	free(top_row(col1up,col2up,col3up,col4up));
	free(bottom_row(col1down, col2down, col3down, col4down));
	free(left_column(row1left, row2left, row3left, row4left));
	free(right_column(row1right, row2right, row3right, row4right));

	return 1;
}

int main(int argc, char **argv)
{
	int col1up = (int)argv[1];
	int col2up = (int)argv[2];
	int col3up = (int)argv[3];
	int col4up = (int)argv[4];

	int col1down = (int)argv[5];
	int col2down = (int)argv[6];
	int col3down = (int)argv[7];
	int col4down = (int)argv[8];

	int row1left = (int)argv[9];
	int row2left = (int)argv[10];
	int row3left = (int)argv[11];
	int row4left = (int)argv[12];

	int row1right = (int)argv[13];
	int row2right = (int)argv[14];
	int row3right = (int)argv[15];
	int row4right = (int)argv[16];

	ft_tab((int)argv[1],(int)argv[2],(int)argv[3],(int)argv[4],(int)argv[5],(int)argv[6],(int)argv[7],(int)argv[8],(int)argv[9],(int)argv[10],(int)argv[11],(int)argv[12],(int)argv[13],(int)argv[14],(int)argv[15],(int)argv[16]);

	return 0;
}
