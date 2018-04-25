/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/20 19:49:25 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_num(t_format **prop, va_list argument)
{
	char	*s;
	int		printed;

	printed = 0;
	s = ft_itoa(va_arg(argument, int));
	if ((*prop)->plus == 1)
		printed += print_sign(s);
	else
		printed += print_space(prop, s);
	ft_putstr(s);
	printed += ft_strlen(s);
	free(s);
	return (printed);
}
