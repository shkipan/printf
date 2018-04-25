/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/15 16:36:15 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_hex_cap(t_format **prop, va_list argument)
{
	char	*s;
	int		printed;
	int		i;

	printed = 0;
	if ((*prop)->hash == 1)
	{
		printed += 2;
		write(1, "0X", 2);
	}
	s = ft_itoa_base(va_arg(argument, int), 16);
	i = -1;
	while (s[++i])
		if (s[i] <= 'f' && s[i] >= 'a')
			s[i] -= 32;
	printed += ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (printed);
}
