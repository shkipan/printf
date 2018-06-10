/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:01:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 16:38:25 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_uni(t_format **prop, va_list argument)
{
	size_t	size;
	size_t	x;
	char	*f;
	char	*s;
	int		c;

	c = va_arg(argument, int);
	s = ft_itoa_base(c, 2);
	x = select_size(ft_strlen(s));
	(*prop)->width -= ((x - 1) <= (*prop)->width) ? x - 1 : 0;
	f = fill_str_chr(prop);
	size = ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : create_uni(s, c);
	(*prop)->minus == 1 ? ft_putstr(f) : create_uni(s, c);
	free(f);
	free(s);
	return (size + x);
}
