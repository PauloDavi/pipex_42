vpath %.c src
vpath %.c src_bonus

NAME := pipex
CFLAGS := -Wextra -Wall -Werror
CFLAGS +=-O3 -march=native -funroll-loops -finline-functions -flto
LIBTF := ./lib/libft
LIBS := -L$(LIBTF) -lft
OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF)

SRCS := pipex.c utils.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

SRCS_BONUS := main.c
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

all: libft $(NAME)

libft: update_submodules
	@$(MAKE) -C $(LIBTF)

update_submodules:
	git submodule update --init --recursive

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

bonus: $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF) clean
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBTF) fclean
	@rm -rf $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all, clean, fclean, re, libft, update_submodules, bonus, rebonus
