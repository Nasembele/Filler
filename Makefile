# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soyster <soyster@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 18:08:25 by soyster           #+#    #+#              #
#    Updated: 2020/03/16 16:42:37 by soyster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = soyster.filler

GCC = gcc -c

FLAG = -Wall -Wextra -Werror -g

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

SRC = main.c parser.c parser_piece.c heatmap.c algorithm.c alg_help.c parser_help.c

HEADER = include/

C_PATH = $(addprefix $(SRC_DIR), $(SRC))
O_PATH = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@gcc $(FLAG) -L $(LIB_DIR) -lft $(O_PATH) -I $(HEADER) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c include/filler.h
	@$(GCC) $(FLAG) -I $(HEADER) -o $@ -c $<
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

clean:
	@/bin/rm -f $(O_PATH)
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

re: fclean all

.PHONY: all fclean clean re