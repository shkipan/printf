/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:49:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 17:53:27 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_char(t_format **prop, va_list argument)
{
	int		num;
	int		printed;

	printed = 0;
	if ((*prop)->plus == 1)
		write(1, "+", 1);
	num = va_arg(argument, int);
	write(1, &(num), 1);
	return (printed);
}
