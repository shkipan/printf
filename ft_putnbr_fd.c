/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:51:06 by dskrypny          #+#    #+#             */
/*   Updated: 2017/11/22 19:42:03 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long res;

	res = (long)n;
	if (res < 0)
	{
		ft_putchar_fd('-', fd);
		res = -res;
	}
	if (res > 10)
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putnbr_fd(res % 10, fd);
	}
	else
		ft_putchar_fd(res + '0', fd);
}
