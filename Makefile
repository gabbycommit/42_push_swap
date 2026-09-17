# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/02 13:49:35 by hukhaw            #+#    #+#              #
#    Updated: 2026/09/17 11:42:05 by hukhaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = libft/libft.a
INCLUDE = -I $(LIBFT_DIR)
SRCS = ps_utils_a.c \
	   ps_utils_b.c \
	   ps_swap.c \
	   ps_push.c \
	   ps_rotate.c \
	   ps_reverse_rotate.c \
	   ps_parse_and_validation.c \
	   ps_compute_disorder_and_symbol.c \
	   ps_bench.c \
	   ps_ranking.c \
	   ps_complex_quick_sort.c \
	   ft_push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
