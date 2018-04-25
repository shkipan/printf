/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/19 18:37:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		wchar_len(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_print_str_uni(t_format **prop, va_list argument)
{
	wchar_t	*s;
	char	*temp;
	int		printed;
	int		i;

	printed = 0;
	if ((*prop)->plus == 1)
		write(1, "+", 1);
	if ((*prop)->minus == 1)
		write(1, "-", 1);
	s = va_arg(argument, wchar_t *);
	i = -1;
	while (s[++i])
	{
		if ((int)s[i] < 128)
			write(1, &(s[i]), 1);
		else
		{
			temp = ft_itoa_base((int)s[i], 2);
			print_uni(temp);
			free(temp);
		}
	}
	printed += i - 1;
	return (printed);
}
