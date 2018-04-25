/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 16:35:55 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_oct(t_format **prop, va_list argument)
{
	char	*s;
	int		printed;

	printed = 0;
	if ((*prop)->hash == 1)
	{
		printed += 1;
		write(1, "0", 2);
	}
	s = ft_itoa_base(va_arg(argument, int), 8);
	printed += ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (printed);
}
