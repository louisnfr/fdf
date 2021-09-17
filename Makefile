# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 02:35:02 by lraffin           #+#    #+#              #
#    Updated: 2021/09/16 15:51:02 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

### EXECUTABLE ###
NAME		= fdf

### INCLUDES ###
INCLUDE		= include
SRC_PATH	= src
OBJ_PATH	= obj
LIBFT_PATH	= libft
MLX_PATH	= minilibx-linux
LIBFT		= -L libft -lft
MLX			= -L minilibx-linux -lmlx -lXext -lX11 -lm

### SOURCE FILES ###
SOURCES = main.c \
		ft_draw.c \
		ft_error.c \
		ft_fdf.c \
		ft_utils.c \
		ft_events.c \
		ft_parse.c

### OBJECTS ###
SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@make -sC $(MLX_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(MLX)
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette $(SRC_PATH)
	-@norminette $(INCLUDE)

push:
	git add .
	git status
	git commit -m fdf
	git push

.PHONY: all clean fclean re norm push
