# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 21:19:59 by jstoneha          #+#    #+#              #
#    Updated: 2019/04/18 22:07:31 by jstoneha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror

SRC_D=src

OBJ_D=obj

INCLUDE=include

NAME=jstoneha.filler

LIBFT=libft/libft.a

LIBFT_C=libft/*.c

SOURCE=main.c\
	   game.c\
	   map.c\
	   insert_piece.c\
	   create_heat_map.c\
	   general.c\
	   clear_n_free.c

SRC=$(addprefix $(SRC_D)/, $(SOURCE))

OBJ=$(addprefix $(OBJ_D)/, $(SOURCE:.c=.o))

$(NAME): $(OBJ) $(LIBFT)
	cc -o $(NAME) $^

$(LIBFT): $(LIBFT_C)
	make -C libft

$(OBJ): $(SRC)
	mkdir -p $(OBJ_D)
	cc -I $(INCLUDE) -c $(SRC)
	mv *.o $(OBJ_D)

re: clean $(NAME)

clean:
	rm -rf $(OBJ_D)
	rm -rf $(NAME)
	rm -rf filler.trace
