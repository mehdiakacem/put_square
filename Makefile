# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 09:47:22 by makacem           #+#    #+#              #
#    Updated: 2022/06/14 11:18:16 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = put_square

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = put_square.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	@rm -f $(OBJ)
	@make clean -C ./mlx

fclean : clean
	@rm -f $(NAME)

re : fclean all