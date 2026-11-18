NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I. -Ilibft -Ift_printf

FT_DIR		= ft_printf
FTPRINTF	= $(FT_DIR)/libftprintf.a

HEADER		= push_swap.h

SRCS		= main.c \
			  srcs/ops_base.c \
			  srcs/ops_base_push.c \
			  srcs/ops_rotate.c \
			  srcs/ops_rrr.c \
			  srcs/utils.c \
			  srcs/utils_second.c \
			  srcs/disorder.c \
			  srcs/min_max.c \
			  srcs/range.c \
			  srcs/quick_entry.c \
			  srcs/quick_sort.c \
			  srcs/parse_num.c \
			  srcs/pushswap_parse.c \
			  srcs/run_algo.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)

$(FTPRINTF):
	$(MAKE) -C $(FT_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(FT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
