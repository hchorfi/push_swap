# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:29:06 by hchorfi           #+#    #+#              #
#    Updated: 2021/07/10 15:19:50 by hchorfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CH = checker

LIBFT_PATH = ./libft

SRCS_CH = checker_bonus.c\
			error_bonus.c\
			init_bonus.c\
			operations_bonus.c\
			operations2_bonus.c\
			utils_bonus.c\
			get_next_line.c\
			get_next_line_utils.c\

SRCS_PS = push_swap.c\
			error.c\
			init.c\
			operations.c\
			operations2.c\
			utils.c\
			utils2.c\
			algo.c\
			algo2.c\

FLAGS = -Werror -Wextra -Wall

ASAN =  -g #-fsanitize=address

$(NAME) :
	make -C $(LIBFT_PATH)
	gcc -g $(ASAN) $(SRCS_PS) $(LIBFT_PATH)/libft.a -o $(NAME)
	
all: $(NAME)

bonus:
	gcc -g $(ASAN) $(SRCS_CH) $(LIBFT_PATH)/libft.a -o $(NAME_CH)

clean:
	make clean -C $(LIBFT_PATH)

fclean:
	rm -rf $(NAME_CH)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

