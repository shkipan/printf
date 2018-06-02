/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:46:00 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/09 14:27:09 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	sym;
	char	*str;

	i = 0;
	str = (char *)s;
	sym = (char)c;
	while (*(str + i))
		i++;
	while (i != 0)
	{
		if (*(str + i) == sym)
			return (str + i);
		i--;
	}
	return (NULL);
}
