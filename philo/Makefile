# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicja <alicja@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 17:39:20 by astefans          #+#    #+#              #
#    Updated: 2024/11/13 17:26:18 by alicja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread -g
RM = rm -f
NAME = philo
SRC = action.c check.c init.c philo.c time.c utils.c
OBJ_PATH = object/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
INC = -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean $(NAME)

.PHONY: all clean fclean re