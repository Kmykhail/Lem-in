# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 15:53:30 by kmykhail          #+#    #+#              #
#    Updated: 2018/07/10 15:05:44 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc 

FLAG = -Wall -Wextra -Werror

RULE = -I. -c

SRC = ft_atoi.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_isdigit.c ft_strcat.c ft_strcmp.c ft_isalnum.c\
 	ft_isalpha.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_strncpy.c\
 	ft_memmove.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_strchr.c ft_strlcat.c ft_strncat.c ft_strncmp.c\
 	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
 	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
 	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
 	ft_strtrim_my.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_strlen_my.c ft_lst_last_my.c\
 	ft_sqrt_my.c ft_recursive_factorial_my.c ft_lstcount_my.c get_next_line.c ft_dig_all.c ft_strjoin_myq.c

OBJ =  $(SRC:%.c=%.o)


all: $(addprefix ../objects/, $(OBJ))

../objects/%.o: %.c
	@$(CC) -c $(FLAG) $< -I ../include -o $@
clean:
	@rm -rf $(addprefix ../objects/, $(OBJ))
	@echo obj. files deleted
fclean: clean

re: fclean all

.PHONY: clean fclean all re
