/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 15:43:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*fill_str_num(t_format **prop, size_t length)
{
	char	*res;
	char	*t;
	size_t	i;
	size_t	size;

	if ((*prop)->width == 0 || length >= (*prop)->width)
		return (ft_strdup(""));
	size = (*prop)->width - length;
	res = ft_strdup("");
	i = 0;
	while (i < size)
	{
		t = res;
		res = ft_strjoin(res, " ");
		free(t);
		i++;
	}
	res[i] = '\0';
	return (res);
}

void			figure_sign(t_format **prop, char **s, long long int c)
{
	char	*temp;

	if ((*prop)->plus && !(*s[0] == '-' || *s[0] == '+'))
	{
		temp = *s;
		*s = (c < 0) ? ft_strjoin("-", *s) : ft_strjoin("+", *s);
		free(temp);
	}
	if ((*prop)->space && !(*s[0] == '-' || *s[0] == '+'))
	{
		temp = *s;
		*s = ft_strjoin(" ", *s);
		free(temp);
	}
}

char			*create_numb(t_format **p, long long int c)
{
	char	*s;
	char	*t;
	size_t	i;
	size_t	iter;

	s = ((*p)->dot && !(*p)->prec && c == 0)
			? ft_strdup("") : ft_itoa(c);
	i = ft_strlen(s) - 1;
	iter = ((*p)->prec) ? (*p)->prec : (*p)->zero * ((*p)->width - (*p)->plus);
	iter = ((*p)->width && (*p)->plus) ? iter : 0;
	(*p)->space = ((*p)->plus) ? 0 : (*p)->space;
	while (iter > 0 && ++i < iter - (*p)->space)
	{
		t = s;
		s = ft_strjoin("0", s);
		free(t);
	}
	figure_sign(p, &s, c);
	return (s);
}

long long int	ft_find_arg_num(t_format **p, va_list argument)
{
	long long int ret;

	if ((*p)->s_mod == 1)
		ret = (char)va_arg(argument, int);
	else if ((*p)->s_mod == 2)
		ret = (short int)va_arg(argument, int);
	else if ((*p)->s_mod == 3)
		ret = va_arg(argument, long int);
	else if ((*p)->s_mod == 4)
		ret = va_arg(argument, long long int);
	else if ((*p)->s_mod == 5)
		ret = va_arg(argument, intmax_t);
	else if ((*p)->s_mod == 6)
		ret = va_arg(argument, size_t);
	else
		ret = va_arg(argument, int);
	return (ret);
}

int				ft_print_num(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	long long int	c;

	(*prop)->zero = ((*prop)->minus) ? 0 : (*prop)->zero;
	c = ft_find_arg_num(prop, argument);
	s = create_numb(prop, c);
	size = ft_strlen(s);
	f = fill_str_num(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : ft_putstr(s);
	(*prop)->minus == 1 ? ft_putstr(f) : ft_putstr(s);
	free(s);
	free(f);
	return (size);
}
