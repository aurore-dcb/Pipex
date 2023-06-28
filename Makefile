# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurore <aurore@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 09:09:28 by aducobu           #+#    #+#              #
#    Updated: 2023/06/28 17:40:15 by aurore           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			pipex

SRCS = 			sources/main.c \
				sources/get_paths.c \
				sources/frees.c \
				sources/get_cmd.c \
				sources/utils.c \
				sources/lst_cmd.c \
				sources/process.c

SRCS_bonus = 	sources_bonus/main_bonus.c \
				sources_bonus/get_paths_bonus.c \
				sources_bonus/frees_bonus.c \
				sources_bonus/get_cmd_bonus.c \
				sources_bonus/utils_bonus.c \
				sources_bonus/lst_cmd_bonus.c \
				sources_bonus/process_bonus.c

OBJS = 			${SRCS:sources/%.c=objects/%.o}

OBJS_bonus = 	${SRCS_bonus:sources_bonus/%.c=objects_bonus/%.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a

all: libft ${NAME}

libft/libft.a:
	make -C libft

${NAME}: objects ${OBJS} libft/libft.a Makefile
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB}

bonus: objects_bonus ${OBJS_bonus} libft/libft.a Makefile
	${CC} ${CFLAGS} -o ${NAME} ${OBJS_bonus} ${LIBFT_LIB}

objects:
	mkdir -p objects

objects_bonus:
	mkdir -p objects_bonus

objects/%.o: sources/%.c | objects
	${CC} ${CFLAGS} -o $@ -c $<

objects_bonus/%.o: sources_bonus/%.c | objects_bonus
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	${RM} objects objects_bonus
	make -C libft clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean

re: fclean all
