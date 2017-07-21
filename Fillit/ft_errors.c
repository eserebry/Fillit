/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:11:20 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/03 22:53:22 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_errors(int str)
{
	if (str == 1)
		ft_putstr_fd("Cant open the file", 2);
	if (str == 2)
		ft_putstr_fd("File is too large", 2);
	if (str == 3)
		ft_putstr_fd("Must only have allowed file", 2);
	exit(1);
}
