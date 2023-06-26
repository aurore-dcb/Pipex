# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurore <aurore@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 16:20:20 by aducobu           #+#    #+#              #
#    Updated: 2023/06/26 14:32:22 by aurore           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = sources/main.c \
		sources/get_paths.c \
		sources/frees.c \
		sources/get_cmd.c \
		sources/first_process.c \
		sources/last_process.c \
		sources/utils.c \
		sources/middle_process.c

OBJS = ${SRCS:sources/%.c=objects/%.o}

CC = cc
# CFLAGS = -Wall -Wextra -Werror
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
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS} 
	${RM} objects
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean

re: fclean all

