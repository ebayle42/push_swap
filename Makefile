NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I. -Ilibft -Ift_printf

FT_DIR		= ft_printf
FTPRINTF	= $(FT_DIR)/libftprintf.a

HEADER		= push_swap.h

SRCS		= main.c \
			  Enzo/ops_base.c \
			  Enzo/ops_base_push.c \
			  Enzo/ops_rotate.c \
			  Enzo/ops_rrr.c \
			  Enzo/utils.c \
			  Enzo/utils_second.c \
			  Enzo/disorder.c \
			  Enzo/min_max.c \
			  Enzo/range.c \
			  Enzo/quick_entry.c \
			  Enzo/quick_sort.c \
			  Tristan/parse_num.c \
			  Tristan/pushswap_parse.c \
			  Tristan/run_algo.c

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
