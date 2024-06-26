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

SRCS =	push_swap.c \
		process_input.c \
		ft_error.c \
		add_nodes.c \
		ft_free.c \
		ft_checkfordup.c \
		ft_checkifsorted.c \
		commands_a.c \
		commands_b.c \
		commands.c \
		sorting.c \
		lst_utils.c \
		scan.c \
		sort_utils_4.c \
		sort_utils.c \
		chunk_utils.c \
		sort_a.c \
		sort_utils_2.c \
		sort_utils_3.c \
		ft_choose.c \
		ft_choose_bottom.c \
		choose_utils.c \
		choose_utils_2.c \
		ft_rough_sort.c \
		ft_last_sort.c \
		sort_small.c

OBJS =	$(SRCS:.c=.o)

LIBFT =	$(LIBFTDIR)/libft.a

LDFLAGS =	-L$(LIBFTDIR) -lft

.PHONY: all clean fclean re

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

