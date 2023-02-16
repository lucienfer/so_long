# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:30:36 by luciefer          #+#    #+#              #
#    Updated: 2023/01/24 14:09:36 by luciefer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = better_so_long

SRC_DIR = src

SRC_BONUS_DIR = bonus

BIN_DIR = ./bin/

SRC =	$(SRC_DIR)/map.c					\
		$(SRC_DIR)/checker.c				\
		$(SRC_DIR)/checker_map.c			\
		$(SRC_DIR)/checker_utils.c			\
		$(SRC_DIR)/get_next_line_utils.c	\
		$(SRC_DIR)/get_next_line.c			\
		$(SRC_DIR)/pathfinding.c			\
		$(SRC_DIR)/pathfinding_utils.c		\
		$(SRC_DIR)/positions.c				\
		$(SRC_DIR)/map_utils.c				\
		$(SRC_DIR)/swap.c					


SRC_BONUS =$(SRC_BONUS_DIR)/map_bonus.c					\
		$(SRC_BONUS_DIR)/checker_bonus.c					\
		$(SRC_BONUS_DIR)/checker_map_bonus.c				\
		$(SRC_BONUS_DIR)/checker_utils_bonus.c			\
		$(SRC_BONUS_DIR)/get_next_line_utils_bonus.c		\
		$(SRC_BONUS_DIR)/get_next_line_bonus.c			\
		$(SRC_BONUS_DIR)/pathfinding_bonus.c				\
		$(SRC_BONUS_DIR)/pathfinding_utils_bonus.c		\
		$(SRC_BONUS_DIR)/positions_bonus.c				\
		$(SRC_BONUS_DIR)/map_utils_bonus.c				\
		$(SRC_BONUS_DIR)/swap_bonus.c					

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)%.o)

OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(BIN_DIR)%.o)

LIB_PATH = ./printf

MLX_PATH = ./mlx

LIB = -L./printf/lib/libft -L./printf/ -lftprintf

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :	$(BIN_DIR) $(NAME)

bonus:	$(NAME_BONUS)

$(OBJ) :		$(BIN_DIR)%.o: $(SRC_DIR)/%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) :		$(BIN_DIR)%.o: $(SRC_BONUS_DIR)/%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(NAME_BONUS) :	$(BIN_DIR) $(OBJ_BONUS)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME_BONUS)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mBonus ! 💸"

$(BIN_DIR):
		@ mkdir -p $(BIN_DIR)

clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ)
		@ rm -f $(OBJ_BONUS)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@ rm -f $(NAME_BONUS)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all $(SRC_BONUS_DIR) clean fclean re
