/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:57:45 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/09 13:22:49 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(res = ft_strdup((const char *)s)))
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, (char)s[i]);
		i++;
	}
	return (res);
}
