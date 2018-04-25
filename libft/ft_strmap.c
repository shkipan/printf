/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:57:10 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/09 13:04:32 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		res[i] = f((char)s[i]);
		i++;
	}
	return (res);
}
