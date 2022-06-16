/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jervasti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:42:30 by jervasti          #+#    #+#             */
/*   Updated: 2021/12/15 14:03:53 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
**	following code does not segfault when null params is sent
**
**	void	ft_bzero(void *s, size_t n)
**	{
**		size_t			i;
**		unsigned char	*c;
**		if (n != 0)
**		{
**			i = 0;
**			c = (unsigned char *)s;
**			if (s)
**			{
**				while (i < n)
**					c[i++] = 0;
**			}
**		}
**	}
*/
