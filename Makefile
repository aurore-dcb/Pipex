# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurore <aurore@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 16:20:20 by aducobu           #+#    #+#              #
#    Updated: 2023/06/19 18:26:11 by aurore           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	sources/main.c \
		sources/get_paths.c \
		sources/frees.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR	= libft
LIBFT_LIB	= libft/libft.a

all:		libft ${NAME}

libft/libft.a:
			make -C libft

${NAME}:	${OBJS} libft/libft.a
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB}

clean:
			${RM} ${OBJS}
			make -C libft clean
			
fclean:		clean
			${RM} ${NAME}
			make -C libft fclean

norm:
			norminette sources
			norminette libft
			norminette headers
			
re:			fclean all