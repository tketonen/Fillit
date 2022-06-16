/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:46:30 by jervasti          #+#    #+#             */
/*   Updated: 2022/02/15 13:45:19 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freemap(char **map, int mapsize)
{
	int	i;

	i = 0;
	while (i < mapsize)
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void *)&map);
}

void	print_map(char **map, int mapsize)
{
	int	i;

	i = 0;
	while (i < mapsize)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** The fuction calculates the minumum mapsize needed for the amount of blocks
** provided by the file.
*/
int	minmapsize(int blocks)
{
	int	size;

	size = 2;
	while (size * size < blocks * 4)
		size++;
	return (size);
}

/*
** Will allocate memory for a square map where the tetriminos will be placed.
** Map will be filled with dots.
*/

char	**create_map(int dimensions)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (dimensions + 1));
	if (!map)
		return (0);
	while (i < dimensions)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (dimensions + 1));
		if (!map[i])
			return (0);
		while (j < dimensions)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][dimensions] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
