/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:21:58 by dskrypny          #+#    #+#             */
/*   Updated: 2018/06/10 16:42:08 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# define EX "+-.*# lhjz{"
#include <stdio.h>

typedef struct			s_format
{
	int		type;
	size_t	width;
	size_t	prec;
	int		plus;
	int		minus;
	int		hash;
	int		zero;
	int		space;
	int		dot;
	int		color;
	int		s_mod;
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
int						ft_print_color(t_format **prop, char *str);
/*
**		list of printing functions
*/
int						ft_print_sym(t_format **prop, char c);
int						ft_print_chr(t_format **prop, va_list argument);
int						ft_print_uni(t_format **prop, va_list argument);
int						ft_print_uns(t_format **prop, va_list argument);
int						ft_print_num(t_format **prop, va_list argument);
int						ft_print_hex(t_format **prop, va_list argument);
int						ft_print_oct(t_format **prop, va_list argument);
int						ft_print_str(t_format **prop, va_list argument);
int						ft_print_str_uni(t_format **prop, va_list argument);
int						ft_print_ptr(t_format **prop, va_list argument);
/*
**		initializing flags and formats
*/
void					ft_init_format(t_format **prop);
t_flag					*ft_create_flag(char sym,
		int(*ft)(t_format **, va_list));
t_flag					*ft_add_flag(t_flag *flags, char sym,
		int (*ft)(t_format **, va_list));
void					ft_init_flags(t_flag **ptr);
char					ft_correct_flags(t_format **f, char flag);

size_t					ft_find_arg(t_format **p, va_list argument);
/*
**		for unicode
*/
void					fill_tab(char tab[4][9], char *s, int n, int size);
int						select_size(int n);
void					print_uni(char *s);
void					create_uni(char *s, int c);
char					*fill_str_chr(t_format **prop);
char					*fill_str_str(t_format **prop, size_t length);

#endif
