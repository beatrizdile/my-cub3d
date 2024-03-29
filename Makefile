vpath %.c src/mandatory
vpath %.c src/bonus

NAME := cub3D
CFLAGS := -Wextra -Wall -Werror
CFLAGS += -g3

CC := cc
RM := rm -rf

LIBTF_DIR := ./lib/libft
LIBMLX := ./lib/MLX42
LIBS := -L$(LIBTF_DIR) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJ_DIR := build
INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR) -I$(LIBTF_DIR) -I$(LIBMLX)/include

SRCS := cub3d.c map_parsing.c mini_map_rendering.c render.c player_movement.c exit.c
SRCS += free.c map_validation.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

SRCS_BONUS := cub3d_bonus.c
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

all: update_submodules libft mlx $(NAME)

init_submodules:
	git submodule update --init

update_submodules: init_submodules
	git submodule foreach git pull origin master

libft:
	@$(MAKE) -C $(LIBTF_DIR)

mlx:
	/nfs/homes/bedos-sa/.local/lib/python3.8/site-packages/cmake/data/bin/cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

bonus: libft $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)

clean: 
	@$(MAKE) -C $(LIBTF_DIR) clean
	@$(RM) -rf $(LIBMLX)/build
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBTF_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

run: all
	./$(NAME) maps/map2.cub

check: all
	valgrind --leak-check=full --suppressions=suppress.sup ./$(NAME) maps/map1.cub

.PHONY: all clean fclean re bonus rebonus libft update_modules init_modules
