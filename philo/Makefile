# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicja <alicja@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 17:39:20 by astefans          #+#    #+#              #
#    Updated: 2024/11/16 20:01:44 by alicja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread -g
RM = rm -f
NAME = philo
SRC = action.c check.c init.c philo.c time.c utils.c
OBJ_PATH = objects/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
INC = -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)+ $(NAME)$(RESET)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_PATH)
	@echo "$(RED)- $(NAME)$(RESET)"

re: fclean $(NAME)

.PHONY: all clean fclean re