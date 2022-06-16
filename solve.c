/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:05:25 by tketonen          #+#    #+#             */
/*   Updated: 2022/02/09 11:55:32 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Overlap function checks if all blocks of the piece fit
** into the map or if the piece is overlapping with previous. 
*/

int	overlap(char **map, t_etris *piece)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = piece->coords[i] + piece->x_offset;
	y = piece->coords[i + 1] + piece->y_offset;
	while (i <= 6 && map[y][x] == '.')
	{
		i += 2;
		x = piece->coords[i] + piece->x_offset;
		y = piece->coords[i + 1] + piece->y_offset;
	}
	if (i == 8)
		return (1);
	return (0);
}

/*
** Piece_to_map function adds the piece to the map on it's 
** coordinates. X/Y offset is added to coordinates so that
** the pieces won't overlap.
*/

void	piece_to_map(char **map, t_etris *piece, char letter)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	x = 0;
	while (i <= 6)
	{
		x = piece->coords[i] + piece->x_offset;
		y = piece->coords[i + 1] + piece->y_offset;
		map[y][x] = letter;
		i += 2;
	}
}

/*
** in_bounds function checks piece's coordinates to see
** if it can fit to the current map on axis x or y.
** This is useful to see if the map is big enough. Else
** we increase the size. Also this helps us to increase
** y offset if we run out of room on x axis.
*/

int	in_bounds(t_etris *piece, int mapsize, char axis)
{
	if (axis == 'y')
	{
		if (piece->coords[1] + piece->y_offset < mapsize && \
					piece->coords[3] + piece->y_offset < mapsize && \
					piece->coords[5] + piece->y_offset < mapsize && \
					piece->coords[7] + piece->y_offset < mapsize)
			return (1);
	}
	else
	{
		if (piece->coords[0] + piece->x_offset < mapsize && \
					piece->coords[2] + piece->x_offset < mapsize && \
					piece->coords[4] + piece->x_offset < mapsize && \
					piece->coords[6] + piece->x_offset < mapsize)
			return (1);
	}
	return (0);
}

/*
** Solver function works as a base function for solving the map.
** It uses loop calls for in bounds function first with y axis and
** then with x. If we encounter overlapping with previous and current
** pieces, we then increase x offset to not be on top of the previous
** piece. If we are not in bounds on axis x, then we increase offset
** on y axis. If the coordinates and offsets are good, we add the
** piece in to the map. Then the function calls itself recursively
** with the next piece on the list. If the next piece wont fit into
** the map, we backtrack and remove the previous piece. Then we 
** increase offset in that piece and try again. Basically we increase
** the offset so that the previous piece makes room for the next one
** on it's left side. With this backtracking method, we can move the
** pieces to get the best fit for all pieces and get the smallest
** square.
** If the pieces wont fit. We have to return 0 and try again with
** bigger map.
*/

int	solver(char **map, int mapsize, t_etris *piece)
{
	if (piece == NULL)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, mapsize, 'y'))
	{
		while (in_bounds(piece, mapsize, 'x'))
		{
			if (overlap(map, piece))
			{
				piece_to_map(map, piece, piece->letter);
				if (solver(map, mapsize, piece->next))
					return (1);
				else
				{
					piece_to_map(map, piece, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}
