/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:21:58 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/20 19:49:56 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
# define EX "+-.*# "

typedef struct			s_format
{
	size_t	width;
	size_t	prec;
	int		plus;
	int		minus;
	int		hash;
	int		zero;
	int		space;
}						t_format;

typedef struct s_flags	t_flag;

struct					s_flags
{
	char	flag;
	int		(*ft)(t_format **, va_list);
	t_flag	*next;
};

int						ft_printf(const char *format, ...);
int						ft_parser(t_format **formating, size_t *index,
		char *format, va_list argument);

int						ft_print_sym(t_format **prop, char c);
int						ft_print_char(t_format **prop, va_list argument);
int						ft_print_uni(t_format **prop, va_list argument);
int						ft_print_num(t_format **prop, va_list argument);
int						ft_print_hex(t_format **prop, va_list argument);
int						ft_print_hex_cap(t_format **prop, va_list argument);
int						ft_print_oct(t_format **prop, va_list argument);
int						ft_print_str(t_format **prop, va_list argument);
int						ft_print_str_uni(t_format **prop, va_list argument);
int						ft_print_ptr(t_format **prop, va_list argument);

void					ft_init_format(t_format **prop);

t_flag					*ft_create_flag(char sym,
		int(*ft)(t_format **, va_list));
t_flag					*ft_add_flag(t_flag *flags, char sym,
		int (*ft)(t_format **, va_list));
void					ft_init_flags(t_flag **ptr);
/*
**for unicode
*/
void					fill_tab(char tab[4][9], char *s, int n, int size);
int						select_size(int n);
void					print_uni(char *s);
/*
**for formats
*/
int						print_sign(char *s);
int						print_space(t_format **prop, char *s);

#endif
