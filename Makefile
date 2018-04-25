# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 19:18:54 by dskrypny          #+#    #+#              #
#    Updated: 2018/04/20 19:47:15 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Wextra -Werror

all:
	make -C libft/
	gcc $(FLAGS) main.c libft/libftprintf.a

re:
	rm -rf a.out
	make all
