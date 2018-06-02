/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 15:58:21 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_hex(t_format **prop, size_t length)
{
	char	*res;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length > (*prop)->width)
		return (ft_strdup(""));
	size = (*prop)->width - length;
	res = (char *)malloc(sizeof(char) * (size - 1));
	i = 0;
	while (i < size)
	{
		res[i] = (!((*prop)->zero)) ? ' ' : '0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_print_hex(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	unsigned int	c;

	c = va_arg(argument, unsigned int);
	s = ft_itoa_base(c, 16);
	if ((*prop)->type == 'X')
		ft_strcapit(s);
	size = ft_strlen(s);
	if ((*prop)->hash && c != 0)
	{
		(*prop)->type == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		size += 2;
	}
	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	f = fill_str_hex(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	free(s);
	return (size);
}
