/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:00:53 by tketonen          #+#    #+#             */
/*   Updated: 2022/02/09 14:23:42 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Shift functions will shift coordinates by n amounts
** on axis x or y.
*/

void	shift_x(t_etris *piece, int n)
{
	piece->coords[0] += n;
	piece->coords[2] += n;
	piece->coords[4] += n;
	piece->coords[6] += n;
}

void	shift_y(t_etris *piece, int n)
{
	piece->coords[1] += n;
	piece->coords[3] += n;
	piece->coords[5] += n;
	piece->coords[7] += n;
}

/*
** Align function checks if coordinates are as near to the 
** upper left corner as possible. It uses shift functions to
** get coordinates near position 0 on x and y axis.
*/

t_etris	*align(t_etris *piece)
{
	while (piece->coords[0] != 0 && \
				piece->coords[2] != 0 && \
				piece->coords[4] != 0 && \
				piece->coords[6] != 0)
		shift_x(piece, -1);
	while (piece->coords[1] != 0 && \
				piece->coords[3] != 0 && \
				piece->coords[5] != 0 && \
				piece->coords[7] != 0)
		shift_y(piece, -1);
	return (piece);
}

/*
** Get_piece function takes all the necessary info from piece
** in buffer (coordinates and letter) and puts those in to struct.
** Coordinates will be saved as> X,Y,X,Y...
** We want the piece to be in the top left corner so we send it
** to align function. 
*/

t_etris	*get_piece(char *buffer, char letter, t_etris *piece)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			if (i >= 5)
				piece->coords[x] = i % 5;
			else
				piece->coords[x] = i;
			piece->coords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece->letter = letter;
	return (align(piece));
}

/*
** Add_to_list function makes the list. It allocates memory to
** struct 'begin'. Then it sends it to get_piece.
** Then we allocate memory for the next struct in list.
** With 'cur' we can move along the list. 
** We return first piece in list, 'begin'.
*/

t_etris	*add_to_list(char *buffer)
{
	static t_etris		*cur;
	static t_etris		*begin;
	static char			letter = 'A';

	if (letter == 'A')
	{
		begin = (t_etris *)malloc(sizeof(t_etris));
		if (begin == NULL)
			return (NULL);
		begin = get_piece(buffer, letter, begin);
		cur = begin;
	}
	else
	{
		cur->next = (t_etris *)malloc(sizeof(t_etris));
		if (cur->next == NULL)
			return (NULL);
		cur->next = get_piece(buffer, letter, cur->next);
		cur = cur->next;
	}
	letter++;
	cur->next = NULL;
	return (begin);
}
