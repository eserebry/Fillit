/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makehash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/03 23:11:32 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_makehash(int i, int j, char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * (i * (i + 1) + 1))))
		return (NULL);
	while (++j < i * (i + 1) - 1)
		if ((j + 1) % (i + 1) != 0)
			str[j] = '.';
		else
			str[j] = '\n';
	str[j] = '\0';
	return (str);
}
