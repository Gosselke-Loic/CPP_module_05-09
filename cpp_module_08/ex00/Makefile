# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 11:19:58 by lgosselk          #+#    #+#              #
#    Updated: 2024/06/26 14:57:34 by lgosselk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	easy_find

DEFAULT		=	\033[0m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m

CC			=	c++
RM			=	rm -rf
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
HEADERS		=	easyfind.hpp easyfind.tpp

OBJS_DIR	=	objs/

FILES		=	main

SRCS		=	$(addsuffix .cpp, $(FILES))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all:	$(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJS_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)$< en compilation!$(DEFAULT)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re:		fclean all

.PHONY:		all clean fclean re