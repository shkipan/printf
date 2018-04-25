/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:58:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/19 15:30:21 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	iter(long long int val, char *str, int *i)
{
	char *tmp;

	tmp = "0123456789abcdef";
	if (val >= 16)
		iter(val / 16, str, i);
	str[(*i)++] = tmp[ABS(val % 16)];
}

char	*ft_base(long long int val)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(32)))
		return (0);
	iter(val, str, &i);
	str[i] = '\0';
	return (str);
}

int		ft_print_ptr(t_format **prop, va_list argument)
{
	char			*s;
	int				printed;

	printed = 2;
	if ((*prop)->plus == 1)
		write(1, "+", 1);
	if ((*prop)->minus == 1)
		write(1, "-", 1);
	write(1, "0x", 2);
	s = ft_base(va_arg(argument, long long int));
	ft_putstr(s);
	printed += ft_strlen(s);
	free(s);
	return (printed);
}
