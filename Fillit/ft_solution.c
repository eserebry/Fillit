/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:10:15 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/03 23:12:44 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*ft_print_tetr(int **tetro, char *hash, int place, int j)
{
	int i;

	i = -1;
	while (++i < 4)
		hash[tetro[j][i] + place] = 'A' + j;
	return (hash);
}

char	*ft_dele_tetr(int **tetro, char *hash, int place, int k)
{
	int i;

	i = -1;
	while (++i < 4)
		hash[tetro[k][i] + place] = '.';
	return (hash);
}

int		ft_put_tetr(int **tetro, char *hash, int place, int m)
{
	int i;

	i = -1;
	while (++i < 4)
		if (hash[tetro[m][i] + place] != '.'
				|| tetro[m][i] + place > ft_strlen(hash))
			return (0);
	return (1);
}

int		ft_count_hash(char *hash)
{
	int i;

	i = -1;
	while (hash[++i] == '.')
		;
	return (i);
}

int		ft_solution(int **tetro, int i, char *hash, int tetnb)
{
	unsigned long	place;
	int				print;

	if (i > tetnb - 1)
	{
		ft_putstr(hash);
		return (1);
	}
	place = -1;
	while (++place < (unsigned long)ft_strlen(hash))
	{
		print = 0;
		if (ft_put_tetr(tetro, hash, place, i))
		{
			print = 1;
			hash = ft_print_tetr(tetro, hash, place, i);
			if (ft_solution(tetro, i + 1, hash, tetnb))
				return (1);
		}
		hash = (print) ? ft_dele_tetr(tetro, hash, place, i) : hash;
	}
	if (!i)
		return (ft_solution(ft_to_hash(tetro, tetnb, ft_count_hash(hash)
		+ 1, -1), 0, ft_makehash(ft_count_hash(hash) + 1, -1, NULL), tetnb));
		return (0);
}
