/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/03 23:06:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**ft_to_hash(int **t, int nbr_tetr, int width, int id)
{
	int		i;

	while (++id < nbr_tetr)
	{
		i = -1;
		while (++i < 4)
			t[id][i] = t[id][i] + (t[id][i] / width);
	}
	return (t);
}
