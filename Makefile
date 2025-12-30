NAME		= pipex

SRC		= main.c \
		append_bonus.c\
		helper_first.c \
		helper_second.c \
		multipipex.c

OBJ		= $(SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) libft.a libftprintf.a
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re
