# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 15:12:35 by xroca-pe          #+#    #+#              #
#    Updated: 2024/03/12 17:40:34 by xroca-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc  
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = push_swap.h checker_bonus/checker.h Makefile

SRC = push_swap.c \
	  handle_errors.c \
	  stack_utils.c	\
	  fill_stack.c \
	  commands/swap.c \
	  commands/push.c \
	  commands/reverse.c \
	  sort_utils.c \
	  movements.c \
	  sort.c \
	  commands/rotate.c	

SRC_BONUS = checker_bonus/checker.c \
	  checker_bonus/get_next_line.c \
	  checker_bonus/get_next_line_utils.c \
	  handle_errors.c \
	  stack_utils.c	\
	  fill_stack.c \
	  commands/swap.c \
	  commands/push.c \
	  commands/reverse.c \
	  sort_utils.c \
	  movements.c \
	  sort.c \
	  commands/rotate.c  

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJ_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus