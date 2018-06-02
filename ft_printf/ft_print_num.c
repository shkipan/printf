/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 09:38:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_num(t_format **prop, size_t length)
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

char	*check_minus(int *c, size_t *size, t_format **prop)
{
	if ((*prop)->plus)
		(*prop)->space = 0;
	if ((*prop)->prec)
		(*prop)->zero = 0;
	if ((*prop)->minus)
		(*prop)->zero = 0;
	*size = 0;
	if (*c < 0 || (*prop)->space)
	{
		*c = (*c < 0) ? -(*c) : *c;
		*size = 1;
		(!((*prop)->space)) ? ft_putchar('-') : ft_putchar(' ');
	}
	if (*c > 0 && (*prop)->plus)
	{
		*size = 1;
		ft_putchar('+');
	}
	return (ft_itoa(*c));
}

int		ft_print_num(t_format **prop, va_list argument)
{
	char	*s;
	char	*f;
	char	*temp;
	size_t	size;
	int		c;

	c = va_arg(argument, int);
	s = check_minus(&c, &size, prop);
	size += ft_strlen(s);
	while (size < (*prop)->prec)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
		size++;
	}
	f = fill_str_num(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(s);
	free(f);
	return (size);
}
