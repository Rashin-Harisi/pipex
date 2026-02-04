NAME		= pipex
BONUS_NAME	= .bonus_state
HEADER      = pipex.h libft/libft.h

COMMON_SRC	= utils/helper_first.c \
		utils/helper_second.c \
		utils/helper_third.c\
		utils/helper_fourth.c\
		utils/cmds_split.c\
		utils/helper_cmds_split.c\
		multipipex.c

MANDATORY_SRC	= main.c\

BONUS_SRC	= bonus/main_bonus.c\
		bonus/append_bonus.c\
		bonus/helper_bonus.c

MANDATORY_OBJ	= $(MANDATORY_SRC:.c=.o)
COMMON_OBJ	= $(COMMON_SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJ) $(COMMON_OBJ)
	@rm -f $(BONUS_NAME)
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) $(COMMON_OBJ) $(LIBFT) -o $(NAME)
	@echo "Pipex Mandatory compiled"

bonus: $(BONUS_NAME)

$(BONUS_NAME):$(LIBFT) $(BONUS_OBJ) $(COMMON_OBJ)
	@rm -f $(NAME) $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(COMMON_OBJ) $(LIBFT) -o $(NAME)
	@touch $(BONUS_NAME)
	@echo "Pipex Bonus compiled"

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(COMMON_OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ) $(BONUS_NAME)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) libft.a libftprintf.a
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re
