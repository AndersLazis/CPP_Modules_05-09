# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 20:51:04 by aputiev           #+#    #+#              #
#    Updated: 2024/01/16 14:08:14 by aputiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CC			= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Bureaucrat.cpp Form.cpp
OBJ			= $(SRC:.cpp=.o)
OBJ_PATH	= ./objects/
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))


all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPP_FLAGS) $(OBJS) -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(CC) $(CPP_FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -f $(NAME)
		
re:		fclean all

.PHONY: all fclean clean re
