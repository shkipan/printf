/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 11:36:38 by dskrypny         ###   ########.fr       */
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

char	*create_hex(t_format **prop, unsigned int c)
{
	char	*s;
	char	*f;

	s = ((*prop)->dot && !((*prop)->prec) && c == 0)
		? ft_strdup("") : ft_itoa_base(c, 16);
	if ((*prop)->hash && c != 0)
	{
		f = s;
		s = (*prop)->type == 'x' ? ft_strjoin("0x", s) : ft_strjoin("0X", s);
		free(f);
	}
	if ((*prop)->type == 'X')
		ft_strcapit(s);
	return (s);
}



int		ft_print_hex(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	unsigned int	c;

	c = va_arg(argument, unsigned int);
	s = create_hex(prop, c);
	size = ft_strlen(s);
	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	f = fill_str_hex(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	free(s);
	return (size);
}
