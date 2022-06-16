/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:46:25 by jervasti          #+#    #+#             */
/*   Updated: 2022/02/09 14:33:41 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_etris
{
	int				coords[8];
	char			letter;
	int				x_offset;
	int				y_offset;
	struct s_etris	*next;
}					t_etris;

int		count_pieces(t_etris *list);
void	shift_x(t_etris *piece, int n);
void	shift_y(t_etris *piece, int n);
t_etris	*align(t_etris *piece);
t_etris	*get_piece(char *buffer, char letter, t_etris *piece);
t_etris	*add_to_list(char *buffer);
int		check_connection(char *buffer);
int		check_square(char *buffer);
int		check_amounts(char *buffer);
t_etris	*list_kreator(int fd);
char	**create_map(int dimensions);
int		minmapsize(int blocks);
int		count_pieces(t_etris *list);
int		map_optimizer(t_etris *list);
int		solver(char **map, int mapsize, t_etris *list);
void	print_map(char **map, int mapsize);
int		in_bounds(t_etris *piece, int mapsize, char axis);
void	piece_to_map(char **map, t_etris *piece, char letter);
int		overlap(char **map, t_etris *piece);
void	freemap(char **map, int mapsize);
void	freelist(t_etris *list);
#endif
