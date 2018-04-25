/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:43:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/02/11 16:54:13 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s;
	char	*dst;

	len = 0;
	while (s1[len])
		len++;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = dst;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (s);
}
