/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:46:23 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/04 19:02:20 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (i < len)
		*(res + i++) = *(s + start++);
	return (res);
}
