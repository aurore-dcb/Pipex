NAME			= 	libft.a

HEADERS			= 	libft.h

SRCS			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
					ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
					ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr.c ft_strstr.c

SRCS_GNL		=	get_next_line.c \
					get_next_line_utils.c

SRCS_PRINTF		=	printf/ft_printf.c \
					printf/ft_print_hex.c \
					printf/ft_print_nbr.c \
					printf/ft_print_ptr.c \
					printf/ft_print_unsigned.c \
					printf/ft_prints.c

bonus 			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS			= ${SRCS:.c=.o}
OBJS_GNL		= ${SRCS_GNL:.c=.o}
OBJS_PRINTF		= ${SRCS_PRINTF:.c=.o}
OBJSbonus 		= ${bonus:.c=.o}

CC 				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			gnl printf ${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

gnl:			$(OBJS_GNL)
						ar -rcs $(NAME) $(OBJS_GNL)
					
printf:			$(OBJS_PRINTF)
						ar -rcs $(NAME) $(OBJS_PRINTF)

bonus:			${OBJSbonus} ${OBJS}
						ar rcs ${NAME} ${OBJSbonus} ${OBJS}

clean:
						${RM} ${OBJS} ${OBJSbonus} ${OBJS_GNL} ${OBJS_PRINTF}

fclean:			clean
						${RM} ${NAME}
	
re:				fclean all

.PHONY: all clean fclean re bonus
