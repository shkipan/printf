/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 17:28:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_str_oct(t_format **prop, size_t length)
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

char	*check_nul(t_format **prop, unsigned int c, size_t *size)
{
	char	*temp;
	char	*s;

	s = ft_itoa_base(c, 8);
	*size = ft_strlen(s);
	if ((*prop)->hash == 1 && c != 0)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
		*size += 1;
	}
	while (*size < (*prop)->prec)
	{
		temp = s;
		s = ft_strjoin("0", s);
		free(temp);
		*size += 1;
	}
	return (s);
}

int		ft_print_oct(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	unsigned int	c;

	c = va_arg(argument, unsigned int);
	s = check_nul(prop, c, &size);
	f = fill_str_oct(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(f);
	free(s);
	return (size);
}
