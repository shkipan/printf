/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:41:29 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/02 17:14:35 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flag	*ft_create_flag(char sym, int (*ft)(t_format**, va_list))
{
	t_flag *res;

	if (!(res = malloc(sizeof(t_flag))))
		return (NULL);
	res->flag = sym;
	res->ft = ft;
	res->next = NULL;
	return (res);
}

t_flag	*ft_add_flag(t_flag *flags, char sym, int (*ft)(t_format**, va_list))
{
	t_flag	*temp;

	temp = flags;
	if (temp == NULL)
		return (ft_create_flag(sym, ft));
	while (temp->next)
		temp = temp->next;
	temp->next = ft_create_flag(sym, ft);
	return (flags);
}

void	ft_init_flags(t_flag **ptr)
{
	*ptr = ft_create_flag('s', &ft_print_str);
	ft_add_flag(*ptr, 'S', &ft_print_str_uni);
	ft_add_flag(*ptr, 'p', &ft_print_ptr);
	ft_add_flag(*ptr, 'd', &ft_print_num);
	ft_add_flag(*ptr, 'D', &ft_print_num);
	ft_add_flag(*ptr, 'i', &ft_print_num);
	ft_add_flag(*ptr, 'o', &ft_print_oct);
	ft_add_flag(*ptr, 'O', &ft_print_oct);
	ft_add_flag(*ptr, 'u', &ft_print_num);
	ft_add_flag(*ptr, 'U', &ft_print_num);
	ft_add_flag(*ptr, 'x', &ft_print_hex);
	ft_add_flag(*ptr, 'X', &ft_print_hex);
	ft_add_flag(*ptr, 'c', &ft_print_chr);
	ft_add_flag(*ptr, 'C', &ft_print_uni);
}
