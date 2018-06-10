/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:34:49 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 16:31:59 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		print_sign(char *s)
{
	if (s[0] == '-')
		write(1, "-", 1);
	else
		write(1, "+", 1);
	return (1);
}

int		print_space(t_format **prop, char *s)
{
	if ((*prop)->space == 0)
		return (0);
	if (!(s[0] == '+' || s[0] == '-'))
		return (0);
	write(1, " ", 1);
	return (1);
}
