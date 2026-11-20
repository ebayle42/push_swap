NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I. -Ilibft -Ift_printf

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

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
			  srcs/run_algo.c \
			  srcs/get_args.c \
			  srcs/bench.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(LIBFT) -o $(NAME)
	@printf '%s\n' \
		'   /\___/\' \
		'  (  * .* )' \
		'  / > 💙 <\' \
		' /_   _   _\' \
		' | |_| |_| | ' \
		' ------------' \
		' | We Enjoy |' \
		' |    𝟒𝟐    |' \
		' |    𝟒𝟐    |' \
		' |__________|'

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FTPRINTF): $(LIBFT)
	$(MAKE) -C $(FT_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
