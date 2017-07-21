/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/03 23:01:08 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_tetrinit(int **t, int nbr_tetros, int width, int id)
{
	int		i;

	while (++id < nbr_tetros)
	{
		i = -1;
		if (width == 2)
			while (++i < 4)
				t[id][i] = t[id][i] - ((t[id][i] / 5) * 2);
		if (width == 3)
			while (++i < 4)
				t[id][i] = t[id][i] - (t[id][i] / 5);
		if (width > 4)
			while (++i < 4)
				t[id][i] = t[id][i] + ((t[id][i] / 5) * (width - 4));
	}
	return (t);
}
