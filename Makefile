# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 15:53:30 by kmykhail          #+#    #+#              #
#    Updated: 2018/07/10 15:18:25 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc -Wall -Wextra -Werror

SRC_NAME = analyze_data.c ants_algo.c ft_parse_algo.c gnl_mod.c helper_ants_algo.c helper_ants_algo_2.c\
	helper_lemin.c helper_parse_algo.c  helper_validatio.c helper_validatio_2.c main.c\
	validation_1.c validation_2.c

OBJO = $(SRC_NAME:.c=.o) 

NAME2 = libftprintf.a

SRC = ft_itoa_an.c modifier.c ft_atoi_ll.c ft_printf.c un_behavior.c ft_itoa_base.c ft_itoa_ui.c \
		ft_char.c ft_check_str.c pointer.c width_prec.c convert_result_to_flag.c \
		add_flag_to_struct.c printf_helper_1.c printf_helper_width_prec.c printf_helper_str_width_prec.c printf_utf.c \
		convert_helper_1.c convert_helper_2.c printf_helper_2.c printf_helper_3.c mix_helper.c

%.o: %.c
	@$(CC) -c $?

FILE_O = objects/*.o

all: $(NAME)

$(NAME): $(NAME2) $(OBJO)
	@$(CC) -o $(NAME) $(OBJO) $(NAME2)
	@rm -rf $(NAME2)
	@echo "\033[3;36mLem-in has been made\033[0m"
$(NAME2): objectdir
	@make -C ft_printf
	@make -C libft
	@ar rc $(NAME2) $(FILE_O)

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf objects
	@rm -rf $(OBJO)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: clean fclean all re
