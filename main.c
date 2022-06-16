/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:55:41 by jervasti          #+#    #+#             */
/*   Updated: 2022/02/10 18:14:11 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_pieces(t_etris *list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

/*
** The function will control the map size for solver funtion.
** It starts by calling for smallest possible map where the blocks could fit.
** If solver fails, the map size will be increased by 1.
** Eventually the function prints the map and clears heap.
*/

int	map_optimizer(t_etris *list)
{
	char	**map;
	int		mapsize;

	mapsize = minmapsize(count_pieces(list));
	map = create_map(mapsize);
	if (map == NULL)
		return (0);
	while (solver(map, mapsize, list) == 0)
	{
		mapsize++;
		freemap(map, mapsize);
		map = create_map(mapsize);
	}
	print_map(map, mapsize);
	freemap(map, mapsize);
	freelist(list);
	return (1);
}

int	check_if_end(int fd, char *buffer, int reader)
{
	reader = read(fd, buffer, 1);
	if (reader == 1 && buffer[0] == '\n')
	{
		reader = read(fd, buffer, BUFF_SIZE);
		if (reader == 0)
			return (-1);
	}
	else if (reader == 1 && buffer[0] != '\n')
		return (-1);
	return (reader);
}

/*
** The function will read the tetriminos to buffer one by one.
** It will then check if the piece is valid.
** Valid piece will be added to a linked list.
** False piece will return an error.
*/
t_etris	*list_kreator(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		reader;
	int		piececounter;
	t_etris	*list;

	piececounter = 0;
	reader = read(fd, &buffer, BUFF_SIZE);
	if (reader < BUFF_SIZE)
		return (NULL);
	while (reader > 0)
	{
		buffer[reader] = '\0';
		piececounter++;
		if (piececounter == 27)
			return (NULL);
		if (!check_amounts(buffer) || !check_square(buffer))
			return (NULL);
		list = add_to_list(buffer);
		if (list == NULL)
			return (NULL);
		reader = check_if_end(fd, buffer, reader);
		if (reader == -1)
			return (NULL);
	}
	return (list);
}

int	main(int ac, char **av)
{
	int		fd;
	t_etris	*list;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fillit 'filename'\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error");
		return (1);
	}
	list = list_kreator(fd);
	if (list == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!map_optimizer(list))
		return (1);
	return (0);
}
