/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:36:36 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 10:33:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_find_flag(size_t *index, char *format, va_list argument,
		t_format **prop)
{
	t_flag		*flags;
	t_flag		*temp;
	int			res;

	res = 0;
	flags = NULL;
	ft_init_flags(&flags);
	while (flags)
	{
		if (flags->flag == *(format + *index))
		{
			*index += 1;
			(*prop)->type = flags->flag;
			res = flags->ft(prop, argument);
		}
		temp = flags->next;
		free(flags);
		flags = temp;
	}
	return (res);
}

int		ft_format(va_list argument, size_t *index, char *format)
{
	t_format	*prop;
	int			printed;

	printed = 0;
	prop = (t_format *)malloc(sizeof(t_format));
	ft_init_format(&prop);
	*index += ft_parser(&prop, index, format, argument);
	printed = ft_find_flag(index, format, argument, &prop);
	if (!(printed))
	{
		printed = ft_print_sym(&prop, *(format + *index));
		*index += 1;
	}
	free(prop);
	return (printed);
}

int		ft_printf(const char *format, ...)
{
	size_t		res;
	size_t		i;
	va_list		argument;

	i = 0;
	res = 0;
	va_start(argument, format);
	while (format[i])
	{
		if (format[i] == '%')
			res += ft_format(argument, &i, (char *)format);
		else
		{
			write(1, &format[i], 1);
			i++;
			res++;
		}
	}
	va_end(argument);
	return (res);
}
