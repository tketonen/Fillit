/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jervasti <jervasti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:17:44 by jervasti          #+#    #+#             */
/*   Updated: 2021/12/26 16:24:04 by jervasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Atoi converts a set of (ASCII) character numbers to int
*/

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					neg;

	result = 0;
	neg = 1;
	i = ft_skipwhitespace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		if (result >= 9223372036854775807 + (unsigned long long)1 && neg == -1)
			return (0);
		if (result > 9223372036854775807)
			return (-1);
		i++;
	}
	return ((int)result * neg);
}
