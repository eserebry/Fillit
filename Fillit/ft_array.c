/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/04 18:05:46 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		*ft_tet_coord(int *tetr, char *str, int i, int j)
{
	while (str[++i])
		if (str[i] == '#')
			tetr[j++] = i;
	return (tetr);
}

char	*ft_row(char *str, int i, int j, int m)
{
	while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
	{
		j = 0;
		while (j < 11)
		{
			i = -1;
			while (++i < 4)
				str[i + j] = str[i + j + 5];
			j = j + 5;
		}
		m = 14;
		while (++m < 19)
			str[m] = '.';
	}
	return (str);
}

char	*ft_colon(char *str, int i, int l, int k)
{
	while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
	{
		l = 0;
		while (l < 16)
		{
			i = -1;
			while (++i < 3)
				str[i + l] = str[i + l + 1];
			l = l + 5;
		}
		k = 3;
		while (k < 19)
		{
			str[k] = '.';
			k = k + 5;
		}
	}
	return (str);
}

int		**ft_array(char *str, int nbr_tetr, int **mem, int i)
{
	nbr_tetr = (ft_strlen(str) + 1) / 21;
	if (!(mem = (int**)malloc(sizeof(*mem) * nbr_tetr)))
		return (NULL);
	i = -1;
	while (++i < nbr_tetr)
	{
		if (!(mem[i] = (int*)malloc(sizeof(mem) * 4)))
			return (NULL);
		mem[i] = ft_tet_coord(mem[i],
				ft_colon(ft_row(ft_strndup(str + i * 21, 20), \
					-1, 0, 14), -1, 0, 3), -1, 0);
	}
	return (mem);
}
