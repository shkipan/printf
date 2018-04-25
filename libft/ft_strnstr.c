/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:14:55 by dskrypny          #+#    #+#             */
/*   Updated: 2017/11/30 20:22:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	s = (char *)haystack;
	if (!(needle[0]))
		return (s);
	while (haystack[i] && (i < len))
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] && (haystack[i + j] == needle[j]) && (i + j) < len)
				j++;
			if (!(needle[j]))
				return (s + i);
		}
		i++;
	}
	return (0);
}
