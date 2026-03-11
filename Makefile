# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:52:48 by merdal            #+#    #+#              #
#    Updated: 2024/04/11 16:17:38 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFTDIR = libft
INCLUDE = -I$(LIBFTDIR)/src

SRCS =	src/push_swap.c \
		src/process_input.c \
		src/ft_error.c \
		src/add_nodes.c \
		src/ft_free.c \
		src/ft_checkfordup.c \
		src/ft_checkifsorted.c \
		src/commands_a.c \
		src/commands_b.c \
		src/commands.c \
		src/sorting.c \
		src/lst_utils.c \
		src/scan.c \
		src/sort_utils_4.c \
		src/sort_utils.c \
		src/chunk_utils.c \
		src/sort_a.c \
		src/sort_utils_2.c \
		src/sort_utils_3.c \
		src/ft_choose.c \
		src/ft_choose_bottom.c \
		src/choose_utils.c \
		src/choose_utils_2.c \
		src/ft_rough_sort.c \
		src/ft_last_sort.c \
		src/sort_small.c

OBJS =	$(SRCS:.c=.o)

LIBFT =	$(LIBFTDIR)/libft.a

LDFLAGS =	-L$(LIBFTDIR) -lft

.PHONY: all clean fclean re

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

