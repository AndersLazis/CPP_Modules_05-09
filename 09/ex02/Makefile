# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 20:51:04 by aputiev           #+#    #+#              #
#    Updated: 2024/03/14 18:51:24 by aputiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pmergeMe

CC			= c++
CPP_FLAGS	= -Wall  -Wextra -Werror -g -std=c++98

SRC			=	main.cpp PmergeMe.cpp

OBJ			= $(SRC:.cpp=.o)
OBJ_PATH	= ./objects/
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))


all: $(OBJ_PATH) $(NAME)
		./$(NAME) 3 2 1 4

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



