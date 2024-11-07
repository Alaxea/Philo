# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicja <alicja@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 17:39:20 by astefans          #+#    #+#              #
#    Updated: 2024/11/07 11:11:30 by alicja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread -g
RM = rm -f
NAME = philo
SRC = main.c init.c utils.c philo.c
OBJ = $(SRC:.c=.o)
INC = -I ./includes/

all: $(NAME)
$(OBJ_PATH)%.o: $(SRC)%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
$(NAME): 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
