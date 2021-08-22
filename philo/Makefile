# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 01:05:37 by sujeon            #+#    #+#              #
#    Updated: 2021/08/21 00:10:12 by sujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR
GREEN       =   "\033[32m"
BLUE		=   "\033[34m"
RESET       =   "\033[0m"

# COMPILE
C			=	gcc
CFLAG		=	-Wall -Wextra -Werror
NAME		=	philo

# FILE
SRC			=	main.c		\
				utils_1.c	\
				utils_2.c	\
				thread.c	\
				behavior.c
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all : $(NAME)

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(OBJ_PATH)
	@$(C) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "COMPILE"$(BLUE) "Philosophers"$(RESET)
	@$(C) $(CFLAG) $^ -o $@
	@echo $(GREEN)"COMPLETE"$(RESET)

clean :
	@echo $(GREEN)"CLEAN"$(RESET)
	@rm -rf $(OBJ_PATH)

fclean : clean
	@echo $(GREEN)"FCLEAN"$(RESET)
	@rm $(NAME)

re : fclean all

.PHONY : all clean fclean re