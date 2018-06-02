/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:37:34 by dskrypny          #+#    #+#             */
/*   Updated: 2017/11/22 19:37:18 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memncmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (i < n && str1[i] == str2[i] && str1[i])
		i++;
	return (str1[i] - str2[i]);
}
