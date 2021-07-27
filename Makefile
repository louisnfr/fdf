# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 17:00:19 by lraffin           #+#    #+#              #
#    Updated: 2021/07/27 15:47:29 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name

NAME =	fdf

# Path

SRC_PATH =		./src/

INCLUDE_PATH =	./include/

OBJ_PATH =		./obj/

# Binary

SRC_NAME =	main.c \
			ft_fdf.c \
			ft_init.c \
			ft_parse.c \
			ft_iso.c \
			ft_error.c \
			ft_events.c \
			ft_line.c

OBJ_NAME =	$(SRC_NAME:.c=.o)

# Files

SRC =	$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ =	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

CC =		gcc $(CFLAGS)

LDFLAGS = -L./libft/

LFT = -lft

CFLAGS =	-Wall -Wextra -Werror -fsanitize=address

MLX =		-lmlx -framework OpenGL -framework AppKit

# Rules

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./libft/
	# @echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	# @echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	# @echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	# @echo "\033[31mFiles .o deleted\n\033[0m"

fclean:	clean
	@make fclean -C ./libft/
	# @echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	# @echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re:		fclean all

norm:
	@norminette $(SRC)
	@norminette $(INCLUDE_PATH)*.h

push:
	git add .
	git status
	git commit -m fdf
	git push

.PHONY:	all clean fclean re, norm, push
