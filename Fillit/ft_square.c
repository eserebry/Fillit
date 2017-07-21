/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/04 17:58:27 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_square(int nbr_tetros, int i, int nbr)
{
	nbr = nbr_tetros;
	if (nbr_tetros == 1)
		return (2);
	nbr = nbr * 4;
	while (i * i < nbr)
		i++;
	return (i);
}
