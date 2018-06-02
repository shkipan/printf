/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 22:39:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	spin_str_uni(wchar_t *s)
{
	int		i;
	char	*temp;

	i = -1;
	while (s[++i])
	{
		if ((int)s[i] < 128)
			write(1, &(s[i]), 1);
		else
		{
			temp = ft_itoa_base((int)s[i], 2);
			create_uni(temp, (int)s[i]);
			free(temp);
		}
	}
}

int		ft_print_str_uni(t_format **prop, va_list argument)
{
	wchar_t	*s;
	char	*temp;
	char	*f;
	int		i;
	int		size;

	i = -1;
	size = 0;
	s = va_arg(argument, wchar_t *);
	while (s[++i])
	{
		temp = ft_itoa_base(s[i], 2);
		size += select_size(ft_strlen(temp));
		free(temp);
	}
	f = fill_str_str(prop, size);
	size += ft_strlen(f);
	(*prop)->minus == 0 ? ft_putstr(f) : spin_str_uni(s);
	(*prop)->minus == 1 ? ft_putstr(f) : spin_str_uni(s);
	free(f);
	return (size);
}
