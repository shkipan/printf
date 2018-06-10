/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:35:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 13:20:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_print_color(t_format **prop, char *str)
{
	if (!ft_strncmp(str, "red", 3))
		ft_putstr("\033[0;31m");
	if (!ft_strncmp(str, "grn", 3))
		ft_putstr("\033[0;32m");
	if (!ft_strncmp(str, "yel", 3))
		ft_putstr("\033[0;33m");
	if (!ft_strncmp(str, "blu", 3))
		ft_putstr("\033[0;34m");
	if (!ft_strncmp(str, "mag", 3))
		ft_putstr("\033[0;35m");
	if (!ft_strncmp(str, "cya", 3))
		ft_putstr("\033[0;36m");
	(*prop)->color = 1;
	return (4);
}
