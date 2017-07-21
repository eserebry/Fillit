/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:58:56 by eupopa            #+#    #+#             */
/*   Updated: 2017/06/04 18:05:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetrminos
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_tetriminos;

void				ft_errors(int msg);
char				*ft_fileread(char *file, int fd, int ret);
int					ft_countblocks(char *str);
int					ft_check(char *str, int i, int len);
char				*ft_makehash(int i, int j, char *str);
int					ft_solution(int **tetro, int i, char *hash,
					int nbr_tetros);
int					**ft_array(char *str, int nbr_tetr, int **mem, int i);
int					**ft_to_hash(int **t, int nbr_tetros, int hash, int id);
int					**ft_tetrinit(int **t, int nbr_tetros, int width, int id);
int					ft_square(int nbr_tetros, int i, int nbr);
void				console(char *str, int *nbr_tetrim, int *square,
					int *i);
int					ft_checkerror(int ac, char *av);
#endif
