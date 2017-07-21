/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:33:39 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/04 18:05:55 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int	ft_count(char *str, int hash, int dot, int nline)
{
	int	i;

	i = -1;
	while (str[++i] && i < 20)
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '.')
			dot++;
		if (str[i] == '\n')
			nline++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
	}
	if (hash != 4 || dot != 12 || nline != 4)
		return (0);
	return (1);
}

int	ft_position(char *str, int i)
{
	if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		return (1);
	if (str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#')
		return (1);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
		return (1);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
		return (1);
	if (str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		return (1);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 9] == '#')
		return (1);
	return (0);
}

int	ft_wrongtetr(char *str, int i, int j)
{
	while (str[j] != '#' && j < 20)
		j++;
	i = j;
	while (++i < 20)
		if (str[i] == '#')
			if (str[i - 1] != '#' && str[i - 5] != '#')
				return (ft_position(&str[j], 0));
	return (1);
}

int	ft_check(char *str, int i, int len)
{
	len = ft_strlen(str);
	if ((len + 1) % 21 != 0)
		return (0);
	if (len > 545)
		return (0);
	while (ft_count(&str[i], 0, 0, 0) && ft_wrongtetr(&str[i], 0, 0))
	{
		if (i + 20 == len)
			return (1);
		i = i + 20;
		if (str[i++] != '\n')
			return (0);
	}
	if (i == len)
		return (1);
	return (0);
}
