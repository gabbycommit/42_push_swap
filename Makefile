# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/02 13:49:35 by hukhaw            #+#    #+#              #
#    Updated: 2026/09/27 09:51:17 by hukhaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

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
	   ps_sort_small.c \
	   ps_is_sorted.c \
	   ps_simple_cost.c \
	   ps_simple_exec.c \
	   ps_simple.c \
	   ps_medium_pull.c \
	   ps_medium_push.c \
	   ps_medium_utils.c \
	   ps_medium_sort.c \
	   ps_complex_quick_sort_utils.c \
	   ps_complex_quick_sort.c \
	   ft_push_swap.c
OBJS = $(SRCS:.c=.o)
BONUS_DIR = bonus
SRCS_BONUS = $(BONUS_DIR)/ps_utils_bonus.c \
			 $(BONUS_DIR)/ps_swap_bonus.c \
			 $(BONUS_DIR)/ps_push_bonus.c \
			 $(BONUS_DIR)/ps_rotate_bonus.c \
			 $(BONUS_DIR)/ps_reverse_rotate_bonus.c \
			 $(BONUS_DIR)/ps_parse_and_validation_bonus.c \
			 $(BONUS_DIR)/get_next_line.c \
			 $(BONUS_DIR)/ps_exec_ops.c \
			 $(BONUS_DIR)/ft_checker_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean
