# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 15:39:00 by dskrypny          #+#    #+#              #
#    Updated: 2018/06/02 09:23:12 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR = ./ft_printf

SOURCE = ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_atoi_bin.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memncmp.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putnstr.c \
			ft_putstr_fd.c \
			ft_str_cut.c \
			ft_strcapit.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			$(DIR)/ft_parser.c \
			$(DIR)/ft_print_chr.c \
			$(DIR)/ft_print_hex.c \
			$(DIR)/ft_print_num.c \
			$(DIR)/ft_print_oct.c \
			$(DIR)/ft_print_ptr.c \
			$(DIR)/ft_print_str.c \
			$(DIR)/ft_print_str_uni.c \
			$(DIR)/ft_print_sym.c \
			$(DIR)/ft_print_uni.c \
			$(DIR)/ft_printf.c \
			$(DIR)/init_format.c \
			$(DIR)/init_flags.c \
			$(DIR)/for_uni.c \
			$(DIR)/print_format.c

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS)  $(SOURCE)
	@ar rcs $(NAME) *.o
	@echo "lib created"

clean:
	 @rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
