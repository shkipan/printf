/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:24:38 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/31 20:51:32 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		is_supp(char c)
{
	int i;

	i = 0;
	while (EX[i])
	{
		if (EX[i] == c || ft_isdigit(c))
			return (1);
		i++;
	}
	return (0);
}

int		skip_num(char *s, t_format **formating, char c)
{
	int k;

	k = 0;
	if (c != '.')
		(*formating)->width = ft_atoi(s);
	else
		(*formating)->prec = ft_atoi(s);
	while (ft_isdigit(*s))
	{
		s++;
		k++;
	}
	return (k - 1);
}

int		ft_parser(t_format **formating, size_t *index, char *format,
		va_list argument)
{
	char		*start;
	int			pos;

	pos = -1;
	start = format + *index + 1;
	while (is_supp(*(start + ++pos)))
	{
		if (*(start + pos) == '0' && (*formating)->zero == 0)
			(*formating)->zero = 1;
		if (ft_isdigit(*(start + pos)))
			pos += skip_num(start + pos, formating, *(start + pos - 1));
		if (*(start + pos) == '+')
			(*formating)->plus = 1;
		if (*(start + pos) == '#')
			(*formating)->hash = 1;
		if (*(start + pos) == ' ')
			(*formating)->space = 1;
		if (*(start + pos) == '-')
			(*formating)->minus = 1;
		if (*(start + pos) == '*')
			(*formating)->width = va_arg(argument, size_t);
	}
	return (pos + 1);
}