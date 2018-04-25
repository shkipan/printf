/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:51:52 by dskrypny          #+#    #+#             */
/*   Updated: 2017/12/09 13:23:40 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_sym(int n)
{
	int		i;
	long	val;

	i = 0;
	val = n;
	if (val < 0)
	{
		i++;
		val = -val;
	}
	while (val / 10 > 0)
	{
		val = val / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		ex;
	int		i;
	long	val;

	val = (long)n;
	i = 0;
	ex = 1;
	if (!(res = (char *)malloc(sizeof(char) * (ft_count_sym(val) + 1))))
		return (NULL);
	if (val < 0)
	{
		res[i++] = '-';
		val = -val;
	}
	while (val / ex > 9)
		ex *= 10;
	while (ex >= 1)
	{
		res[i++] = '0' + val / ex;
		val = val % ex;
		ex /= 10;
	}
	res[i] = '\0';
	return (res);
}
