/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 22:39:45 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_str(t_format **prop, size_t length)
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
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_print_str(t_format **prop, va_list argument)
{
	char	*s;
	char	*f;
	size_t	size;

	s = va_arg(argument, char *);
	size = ft_strlen(s);
	f = fill_str_str(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	return (size);
}
