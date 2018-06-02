/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:55:04 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 19:47:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_init_format(t_format **prop)
{
	(*prop)->width = 0;
	(*prop)->prec = 0;
	(*prop)->plus = 0;
	(*prop)->minus = 0;
	(*prop)->hash = 0;
	(*prop)->zero = 0;
	(*prop)->space = 0;
}
