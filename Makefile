# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 16:20:20 by aducobu           #+#    #+#              #
#    Updated: 2023/06/20 13:08:54 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = sources/main.c \
		sources/get_paths.c \
		sources/frees.c \
		sources/get_cmd.c

OBJS = ${SRCS:sources/%.c=objects/%.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a

all: libft ${NAME}

libft/libft.a:
	make -C libft

${NAME}: objects ${OBJS} libft/libft.a
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB}

objects:
	mkdir -p objects

objects/%.o: sources/%.c | objects
	${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<

clean:
	${RM} ${OBJS}
	${RM} objects
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean

norm:
	norminette sources
	norminette libft
	norminette headers

re: fclean all

