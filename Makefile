# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:29:06 by hchorfi           #+#    #+#              #
#    Updated: 2021/06/18 14:56:45 by hchorfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CH = checker

LIBFT_PATH = ./libft

SRCS_CH = checker.c\
			error.c\
			init.c\
			operations.c\
			operations2.c\
			utils.c\
			get_next_line.c\
			get_next_line_utils.c\

SRCS_PS = push_swap.c\
			error.c\
			init.c\
			operations.c\
			operations2.c\
			utils.c\

FLAGS = -Werror -Wextra -Wall

ASAN =  -g #-fsanitize=address

$(NAME) :
	make -C $(LIBFT_PATH)
	gcc -g $(ASAN) $(SRCS_CH) $(LIBFT_PATH)/libft.a -o $(NAME_CH)
	gcc -g $(ASAN) $(SRCS_PS) $(LIBFT_PATH)/libft.a -o $(NAME)
	
all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)

fclean:
	rm -rf $(NAME_CH)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

