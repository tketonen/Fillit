/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:02:48 by jervasti          #+#    #+#             */
/*   Updated: 2022/01/03 09:11:32 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strstr() function finds the first occurrence of the substring needle
** in the string haystack.
** The terminating null bytes ('\0') are not compared.
**
** The function returns a pointer to the beginning of the located substring,
** or NULL if the substring is not found.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
