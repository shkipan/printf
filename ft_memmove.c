/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:45:30 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/23 20:50:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*str;
	char		*dest;

	dest = dst;
	str = src;
	if (dest <= str)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = str[i - 1];
			i--;
		}
	}
	return (dest);
}
