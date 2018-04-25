/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 16:58:22 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_str(t_format **prop, va_list argument)
{
	char	*s;
	int		printed;

	printed = 0;
	if ((*prop)->plus == 1)
		write(1, "+", 1);
	if ((*prop)->minus == 1)
		write(1, "-", 1);
	s = va_arg(argument, char *);
	printed += ft_strlen(s);
	ft_putnstr(s, printed);
	return (printed);
}
