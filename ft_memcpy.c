/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:35:14 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/04 19:09:58 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	unsigned char		*dest;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned const char *)src;
	while (i < n)
	{
		*(dest + i) = *(str + i);
		i++;
	}
	return (dst);
}
