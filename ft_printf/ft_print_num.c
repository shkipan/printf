/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 15:25:31 by dskrypny         ###   ########.fr       */
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
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	figure_sign(t_format **prop, char **s, long long int c)
{
	char	*temp;

	if (((int)c >= 0 && (*prop)->plus) || ((int)c < 0 && *s[0] != '-'))
	{
		temp = *s;
		*s = ((int)c < 0) ? ft_strjoin("-", *s) : ft_strjoin("+", *s);
		free(temp);
	}
	if ((*prop)->space && !(*s[0] == '-' || *s[0] == '+'))
	{
		temp = *s;
		*s = ft_strjoin(" ", *s);
		free(temp);
	}
}

char	*create_numb(t_format **prop, long long int c)
{
	char	*s;
	char	*t;
	size_t	i;

	s = ((*prop)->dot && !(*prop)->prec && c == 0)
		? ft_strdup("") : ft_itoa((int)c);
	if ((int)c < 0 && (*prop)->prec > ft_strlen(s))
		s[0] = '0';
	i = ft_strlen(s) - 1;
	while (++i < (*prop)->prec)
	{
		t = s;
		s = ft_strjoin("0", s);
		free(t);
	}
	figure_sign(prop, &s, c);
	return (s);
}

int		ft_print_num(t_format **prop, va_list argument)
{
	char			*s;
	char			*f;
	size_t			size;
	long long int	c;

	(*prop)->space = ((*prop)->plus) ? 0 : (*prop)->space;
	(*prop)->zero = ((*prop)->prec || (*prop)->minus) ? 0 : (*prop)->zero;
	c = va_arg(argument, long long);
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
