/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:15:05 by tketonen          #+#    #+#             */
/*   Updated: 2022/02/10 09:53:54 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freelist(t_etris *list)
{
	t_etris	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

/*
** The function will check if a piece has three or four connections.
** A connection comes if there is a block below or to the right of the current
** block.A valid block has at least three connections.
*/

int	check_connection(char *buffer)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			if ((i + 1) < 20 && buffer[i + 1] == '#')
				counter++;
			if ((i + 5) < 20 && buffer[i + 5] == '#')
				counter++;
		}
		i++;
	}
	if (counter == 3 || counter == 4)
		return (1);
	return (0);
}

/*
** The function will check it there's always a \n after four characters.
** The character can't be anywhere else.
*/

int	check_square(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			if ((i + 1) % 5 != 0)
				return (0);
		i++;
	}
	return (check_connection(buffer));
}

/*
** The function counts all the characters from the buffer.
** It will return 1 if it finds the correct amount.
*/

int	check_amounts(char *buffer)
{
	int	newline;
	int	hashtag;
	int	dot;

	newline = 0;
	hashtag = 0;
	dot = 0;
	while (*buffer)
	{
		if (*buffer == '#')
			hashtag++;
		if (*buffer == '\n')
			newline++;
		if (*buffer == '.')
			dot++;
		buffer++;
	}
	if (newline == 4 && hashtag == 4 && dot == 12)
		return (1);
	return (0);
}
