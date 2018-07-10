# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 18:49:20 by kmykhail          #+#    #+#              #
#    Updated: 2018/07/10 15:06:27 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c -Wall -Wextra -Werror

SRC = ft_itoa_an.c modifier.c ft_atoi_ll.c ft_printf.c un_behavior.c ft_itoa_base.c ft_itoa_ui.c \
		ft_char.c ft_check_str.c pointer.c width_prec.c convert_result_to_flag.c \
		add_flag_to_struct.c printf_helper_1.c printf_helper_width_prec.c printf_helper_str_width_prec.c printf_utf.c \
		convert_helper_1.c convert_helper_2.c printf_helper_2.c printf_helper_3.c mix_helper.c 

OBJ =  $(SRC:%.c=%.o)

all: $(addprefix ../objects/, $(OBJ))

../objects/%.o: %.c
	@$(CC) $< -I ../include -o $@
	
clean:
	@rm -rf $(addprefix ../objects/, $(OBJ))
	@echo ft_printf obj. deleted

fclean: clean

re: fclean all

.PHONY: clean fclean all re
