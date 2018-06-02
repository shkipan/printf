/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:06:01 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/17 09:10:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static int		ft_fill(char *res, const char *s, int i, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		res[j] = s[i + j];
		j++;
	}
	res[j] = '\0';
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		size;

	if (!(res = (char **)malloc(sizeof(char *) + (ft_count(s, c) + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (k < ft_count(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			size = 0;
			while (s[i + size] != c && s[i + size])
				size++;
			res[k] = (char *)malloc(sizeof(char) * (size + 1));
			k += ft_fill(res[k], s, i, size);
			i += size;
		}
	}
	res[k] = NULL;
	return (res);
}
