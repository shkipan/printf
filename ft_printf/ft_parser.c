/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:24:38 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 16:37:59 by dskrypny         ###   ########.fr       */
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
	if (c == '{')
		return (ft_print_color(formating, s));
	if (c == '.')
		(*formating)->dot = 1;
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

void	ft_parser_2(t_format **formating, char *start, int pos,
		va_list argument)
{
	if (*(start + pos) == '-')
		(*formating)->minus = 1;
	else if (*(start + pos) == '*')
		(*formating)->width = va_arg(argument, size_t);
	else if (*(start + pos) == '.')
		(*formating)->dot = 1;
	else if (*(start + pos) == '+')
		(*formating)->plus = 1;
	else if (*(start + pos) == '#')
		(*formating)->hash = 1;
	else if (*(start + pos) == ' ')
		(*formating)->space = 1;
	else if (*(start + pos) == 'l')
		(*formating)->s_mod = ((*formating)->s_mod == 3) ? 4 : 3;
	else if (*(start + pos) == 'h')
		(*formating)->s_mod = ((*formating)->s_mod == 2) ? 1 : 2;
	else if (*(start + pos) == 'j')
		(*formating)->s_mod = 5;
	else if (*(start + pos) == 'z')
		(*formating)->s_mod = 6;
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
		if (*(start + pos) == '0' && *(start + pos - 1) != '.')
			(*formating)->zero = 1;
		else if (ft_isdigit(*(start + pos)))
			pos += skip_num(start + pos, formating, *(start + pos - 1));
		else if (*(start + pos) == '{')
			pos += skip_num(start + pos + 1, formating, *(start + pos));
		ft_parser_2(formating, start, pos, argument);
	}
	return (pos + 1);
}
