/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:35:37 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/04 19:10:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	unsigned char		*dest;
	unsigned char		sym;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned const char *)src;
	sym = (unsigned char)c;
	while (i < n)
	{
		if ((*dest++ = *str++) == sym)
			return (dest);
		i++;
	}
	return (NULL);
}
