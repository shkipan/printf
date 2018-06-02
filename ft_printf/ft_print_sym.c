/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:49:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 10:35:55 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_sym(t_format **prop, char c)
{
	char	*f;
	int		size;

	f = fill_str_chr(prop);
	size = ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putchar(c);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putchar(c);
	free(f);
	return (size + 1);
}
