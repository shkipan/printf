/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:58:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 15:08:53 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_bin(char *s)
{
	int		len;
	int		res;
	int		ex;

	res = 0;
	ex = 1;
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		res += ex * (s[len] - '0');
		ex *= 2;
		len--;
	}
	return (res);
}
