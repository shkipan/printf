/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:51:06 by dskrypny          #+#    #+#             */
/*   Updated: 2017/11/30 19:06:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long res;

	res = (long)n;
	if (res < 0)
	{
		ft_putchar('-');
		res = -res;
	}
	if (res > 10)
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
	else
		ft_putchar(res + '0');
}
