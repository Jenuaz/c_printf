# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 20:11:40 by ylisyak           #+#    #+#              #
#    Updated: 2018/09/03 22:20:41 by ylisyak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = parsing.c ft_printf.c hex.c ft_put_count.c ft_put_char.c octal.c

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I./$(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft
