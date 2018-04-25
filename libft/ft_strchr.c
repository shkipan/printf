/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:45:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/02/22 19:04:18 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sym;

	sym = (char)c;
	while (*s)
	{
		if (*s == sym)
			return ((char *)s);
		s++;
	}
	if (sym == '\0')
		return ((char *)s);
	return (NULL);
}
