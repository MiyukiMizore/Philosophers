# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 11:38:44 by mfusil            #+#    #+#              #
#    Updated: 2022/10/28 12:39:52 by mfusil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAG = -Wall -Wextra -Werror -pthread

PHILO = src/main.c\
		src/start.c\
		src/init_rules.c\
		src/death_checker.c

UTILS = utils/is_digit.c\
		utils/ft_atoi.c\
		utils/convert_str.c\
		utils/time_spent.c\
		utils/ft_sleep.c

ERROR = check_error/check_error.c

ALL_SRC = $(PHILO)\
		  $(UTILS)\
		  $(ERROR)

OBJS = $(ALL_SRC:.c=.o)

all : $(NAME)

alln : all
		norminette

.c.o:
	@cc -o $@ -c $<

$(NAME) : $(OBJS)
		@cc $(CFLAG) -o $(NAME) $(OBJS)
		@echo "$(GREEN)$(BOLD)Executable Created"
clean :
		@rm -rf a.out
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : clean all

#----------------------COLORS----------------------
GREEN=\x1b[32m
BOLD=\033[1m
