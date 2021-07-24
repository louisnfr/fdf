# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 17:00:19 by lraffin           #+#    #+#              #
#    Updated: 2021/07/24 17:27:25 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			fdf.a

CC= 			gcc

CFLAGS=			-Wall -Wextra -Werror

SRC_PATH=		src/

SRC_FILES=		src/fdf.c \
				src/fdf_utils.c

INCLUDE_PATH=	include/

LIBFT_PATH=		libft/

LIBFT_LIB=		libft.a

SRC_OBJS=		${SRC_FILES:.c=.o}

RM=				rm -f

AR=				ar rcs

LIBFT_OBJS=		${LIBFT_PATH}*.o

LIBFTMAKE=		$(MAKE) -C ${LIBFT_PATH} bonus

all:			${NAME}

${NAME}:    	${SRC_OBJS} libmake
				${AR} ${NAME} ${SRC_OBJS} ${LIBFT_OBJS}

libmake:
				${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRC_OBJS}

fclean: 		clean
				${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:				fclean all

.PHONY:			all clean fclean re libmake
