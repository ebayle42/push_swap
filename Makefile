NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I. -Ilibft 

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

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

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
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

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
