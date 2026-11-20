NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I.

HEADER		= push_swap.h

SRCS		= main.c \
			  ops_base.c \
			  ops_base_push.c \
			  ops_rotate.c \
			  ops_rrr.c \
			  utils.c \
			  utils_second.c \
			  disorder.c \
			  min_max.c \
			  range.c \
			  quick_entry.c \
			  quick_sort.c \
			  parse_num.c \
			  pushswap_parse.c \
			  run_algo.c \
			  get_args.c \
			  bench.c \
			  ft_split.c \
			  ft_putstr_fd.c \
			  ft_putnbr_fd.c \
			  ft_putchar_fd.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
