/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:20:31 by jervasti          #+#    #+#             */
/*   Updated: 2022/02/10 18:04:57 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Write a function that returns a line read from a file descriptor.
**
** The return value can be 1, 0 or -1 depending on whether
**  1) a line has been read,
**  0) when the reading has been completed,
** -1) or if an error has happened respectively.
*/

static void	strdestroyer(char **str)
{
	ft_strclr(*str);
	free(*str);
	*str = NULL;
}

static int	seek_and_destroy(char **str)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strdup(tmp);
	strdestroyer(&tmp);
	if (!*str)
		return (-1);
	return (1);
}

static int	linecheck(char **line, char **bank)
{
	char	*tmp;

	*bank = ft_strchr(*line, '\n');
	if (*bank)
	{
		**bank = '\0';
		*bank += 1;
		if (**bank == '\0')
			*bank = NULL;
		else
		{
			tmp = *bank;
			*bank = ft_strdup(*bank);
			ft_strclr(tmp);
			if (!*bank)
				return (-1);
		}
		return (seek_and_destroy(line));
	}
	return (0);
}

static int	collect(char **line, char *buf, char **bank)
{
	char	*tmp;

	if (*line == NULL)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		strdestroyer(&tmp);
	}
	if (!*line)
		return (-1);
	return (linecheck(line, bank));
}

int	get_next_line(const int fd, char **line)
{
	static char	*pbank[FS + 1];
	char		buffer[BUFSIZE + 1];
	ssize_t		status;

	if (read(fd, &buffer, 0) || fd < 0 || fd > FS || !line || BUFSIZE <= 0)
		return (-1);
	*line = pbank[fd];
	if (pbank[fd] != NULL)
	{
		status = linecheck(line, &pbank[fd]);
		if (status != 0)
			return (status);
	}
	status = read(fd, &buffer, BUFSIZE);
	while (status > 0)
	{
		buffer[status] = '\0';
		status = collect(line, buffer, &pbank[fd]);
		if (status != 0)
			return (status);
		status = read(fd, &buffer, BUFSIZE);
	}
	if (status == -1)
		return (status);
	return (!!*line);
}
