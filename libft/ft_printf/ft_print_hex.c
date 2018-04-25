/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 17:00:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_hex(t_format **prop, va_list argument)
{
	char	*s;
	int		printed;

	printed = 0;
	if ((*prop)->hash == 1)
	{
		printed += 2;
		write(1, "0x", 2);
	}
	s = ft_itoa_base(va_arg(argument, int), 16);
	printed += ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (printed);
}
