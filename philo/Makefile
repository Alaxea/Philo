# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astefans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 17:39:20 by astefans          #+#    #+#              #
#    Updated: 2024/08/09 17:39:26 by astefans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pthread
RM = rm -f
NAME = philo
SRC = 
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re
