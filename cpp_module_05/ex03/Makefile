# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 15:19:52 by lgosselk          #+#    #+#              #
#    Updated: 2024/07/05 10:28:55 by lgosselk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	intern

DEFAULT		=	\033[0m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m

CC			=	c++
RM			=	rm -rf
TO_REMOVE	=	Home_shrubbery
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
HEADERS		=	Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

OBJS_DIR	=	objs/

FILES		=	main Bureaucrat AForm PresidentialPardonForm ShrubberyCreationForm \
				RobotomyRequestForm Intern

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
	@$(RM) $(TO_REMOVE)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re:		fclean all

.PHONY:		all clean fclean re