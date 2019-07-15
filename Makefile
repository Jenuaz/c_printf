# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 20:11:40 by ylisyak           #+#    #+#              #
#    Updated: 2019/04/28 16:53:55 by ylisyak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = parsing.c         \
      ft_printf.c       \
      ft_char_char.c    \
      ft_char_string.c  \
      ft_digits_di.c    \
      ft_digits_hex.c   \
      ft_digits_o.c     \
      ft_percent.c      \
      ft_pointer.c      \
      ft_put_char.c     \
      ft_put_count.c    \
      ft_flow_f.c       \
      ft_flow_exponent.c \
      ft_flow_mantissa.c

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I./$(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
