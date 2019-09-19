# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstoneha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:37:44 by jstoneha          #+#    #+#              #
#    Updated: 2018/12/16 23:27:32 by jstoneha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJ = *.o

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRCS) -I.
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
