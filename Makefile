# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vsudak <vsudak@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2026/01/25 18:27:28 by vsudak        #+#    #+#                  #
#    Updated: 2026/01/25 20:11:30 by vsudak        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_push_header.h
SRC =	sort.c \
		radix.c \
		ps_utils2.c \
		ps_utilis.c \
		operations_3.c \
		operations_2.c \
		operations_1.c \
		main.c \
		initialization_1.c \
		ft_split.c \
		chr_stack.c
OBJ = $(SRC:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re