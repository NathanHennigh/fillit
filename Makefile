# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 13:27:36 by nhennigh          #+#    #+#              #
#    Updated: 2019/03/01 13:28:14 by nhennigh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I libft/

SRC = main.c \
	  reader.c \
	  solver.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)
	make -C libft

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
