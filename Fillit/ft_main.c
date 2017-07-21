/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/04 17:59:54 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	char	*str;
	int		nbr_tetrim;
	int		square;
	int		i;

	if (!ft_checkerror(ac, av[1]))
		return (0);
	i = -1;
	str = ft_fileread(av[1], 0, 0);
	nbr_tetrim = (ft_strlen(str) + 1) / 21;
	square = ft_square(nbr_tetrim, 2, 0);
	console(str, &nbr_tetrim, &square, &i);
	return (0);
}
