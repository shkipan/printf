/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:30:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/20 19:49:38 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <locale.h>
#include <stdio.h>
int		main(void)
{
	int x;
	int s1 = 0;
	int s2;
	wchar_t *str;

	x = 255;
	str = (wchar_t *)malloc(sizeof(wchar_t) * 4);
	str[0] = 97;
	str[1] = 98;
	str[2] = 66376;
	str[3] = '\0';
	setlocale(LC_ALL, "");
	s1 = ft_printf("|%+ d|\n", 12);
	s2 = printf("|%.5d|\n", 12);
	printf("%d %d\n", s1, s2);
	free(str);
	while (1);
	return (0);
}
