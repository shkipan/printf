/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:49:25 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 10:36:31 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_chr(t_format **prop)
{
	char	*res;
	size_t	i;

	if ((*prop)->width == 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (*prop)->width);
	i = -1;
	while (++i < (*prop)->width - 1)
		res[i] = ' ';
	res[i] = '\0';
	return (res);
}

int		ft_print_chr(t_format **prop, va_list argument)
{
	int		ch;
	char	*f;
	int		size;

	ch = va_arg(argument, int);
	f = fill_str_chr(prop);
	size = ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putchar(ch);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putchar(ch);
	free(f);
	return (size + 1);
}
