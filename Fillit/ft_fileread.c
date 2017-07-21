/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:02:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/06/04 17:51:14 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#define BUF_SIZE 600

char		*ft_readstr(const char *s1)			//ft_strdup
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_fileread(char *file, int fd, int ret)
{
	char	*buffer;
	char	*output;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_errors(1);
		return (NULL);
	}
	if ((buffer = (char*)malloc(sizeof(*buffer) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	ret = read(fd, buffer, BUF_SIZE);
	buffer[ret] = '\0';
	output = ft_readstr(buffer);
	close(fd);
	free(buffer);
	return (output);
}

int			ft_checkerror(int ac, char *av)
{
	char	*str;

	if (ac != 2)
		ft_errors(1);
	str = ft_fileread(av, 0, 0);
	if (ft_check(str, 0, 0) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

void		console(char *str, int *nbr_tetrim, int *square, int *i)
{
	int		**poz;

	poz = ft_array(str, 0, NULL, -1);
	if (*nbr_tetrim == 1 && (poz[0][0] != 0 || poz[0][1] != 1
		|| poz[0][2] != 5 || poz[0][3] != 6))
		(*square)++;
	while (++(*i) < *nbr_tetrim)
		if ((poz[*i][3] == 3 || poz[*i][3] == 15) && *square == 3)
		{
			(*square)++;
			break ;
		}
	ft_solution(ft_tetrinit(poz, *nbr_tetrim, *square, -1), 0,
			ft_makehash(*square, -1, NULL), (*nbr_tetrim));
}
