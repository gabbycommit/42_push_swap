# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/02 13:49:35 by hukhaw            #+#    #+#              #
#    Updated: 2026/09/03 10:19:59 by hukhaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = libft/libft.a
SRCS = ps_utils_a.c \
	   ps_utils_b.c \
	   ps_swap.c \
	   ps_push.c \
	   ps_rotate.c \
	   ps_reverse_rotate.c \
	   ps_disorder_metric.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
