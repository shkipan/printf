/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:06:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 15:57:53 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_find_arg(t_format **p, va_list argument)
{
	size_t ret;

	if ((*p)->s_mod == 1)
		ret = (unsigned char)va_arg(argument, int);
	else if ((*p)->s_mod == 2)
		ret = (unsigned short int)va_arg(argument, int);
	else if ((*p)->s_mod == 3)
		ret = va_arg(argument, unsigned long int);
	else if ((*p)->s_mod == 4)
		ret = va_arg(argument, unsigned long long int);
	else if ((*p)->s_mod == 5)
		ret = va_arg(argument, uintmax_t);
	else if ((*p)->s_mod == 6)
		ret = va_arg(argument, size_t);
	else
		ret = va_arg(argument, unsigned int);
	return (ret);
}
