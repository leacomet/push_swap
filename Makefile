# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acomet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:18 by acomet            #+#    #+#              #
#    Updated: 2023/02/23 15:27:52 by acomet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BONUS	=	checker

LIBFT		=	libft/libft.a

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-L $(dir $(LIBFT))
CPPFLAGS	=	-I libft -I .
LDLIBS 		=	-l:libft.a

LIBMDF		=	libft_modified/
INSTR		=	instructions/
SRCS		= 	main/push_swap.c \
				$(LIBMDF)libft_modified.c $(LIBMDF)lst_functions.c \
				errors/check_errors.c \
				grid/grid.c \
				stack_a/stack_a.c \
				free/free.c \
				count_of_number/count_of_number.c \
				normalized/normalized.c \
				sorts/sort_algorithm.c sorts/sort_little_number.c sorts/sort_verif.c sorts/sort_optimization.c \
				$(INSTR)pushes.c $(INSTR)reverses.c $(INSTR)rotates.c $(INSTR)swaps.c

SRCS_BONUS	=	bonus/checker_acomet.c \
				$(LIBMDF)libft_modified.c $(LIBMDF)lst_functions.c \
				errors/check_errors.c \
				grid/grid.c \
				stack_a/stack_a.c \
				free/free.c \
				sorts/sort_verif.c \
				bonus/pushes.c bonus/reverses.c bonus/rotates.c bonus/swaps.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS 		= 	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all: $(NAME)
.PHONY: all

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

bonus: $(NAME_BONUS)
.PHONY: bonus

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C ./libft clean
.PHONY: clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C ./libft fclean
.PHONY: fclean

re: fclean all
.PHONY: re

run: all
	./$(NAME) 5 4 3 2 1

run2: all
	valgrind ./$(NAME) 5 4 3 2 1

rebonus: fclean bonus
.PHONY: rebonus
