/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:33:24 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/04 19:07:23 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1 && *str1 == *str2 && (n - 1 > 0))
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
