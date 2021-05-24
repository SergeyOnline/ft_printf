# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 10:54:42 by sbroderi          #+#    #+#              #
#    Updated: 2020/02/17 10:54:45 by sbroderi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

DIR = src/

C_FILES = ft_calloc.c\
	ft_itoa.c\
	ft_printf.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_strjoin.c\
	ft_strlen.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_print_char.c\
	ft_print_string.c\
	ft_digits_in_number.c\
	ft_print_int.c\
	ft_print_int_without_flags.c\
	ft_print_int_on_left_side.c\
	ft_print_int_on_right_side.c\
	ft_hextoa.c\
	ft_print_pointer.c\
	ft_print_uint_on_left_side.c\
	ft_print_uint_on_right_side.c\
	ft_print_uint_without_flags.c\
	ft_print_uint.c\
	ft_uitoa.c\
	ft_str_uppercase.c\
	ft_default_flags.c

SRC = $(addprefix $(DIR), $(C_FILES))

FLAGS = -Wall -Werror -Wextra

OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: all, clean, clean, re

all: $(NAME) 

$(NAME): $(OBJ)
	
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -I./includes -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all