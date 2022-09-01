SRCS = ft_strlen.c \
				ft_strlcpy.c \
				ft_strchr.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_split.c \
				ft_itoa.c \
				ft_strncmp.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_realloc.c \
				get_next_line.c \

NAME = libft.a

CC = cc

LIB = ar -rcs

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

OBJS = 		${SRCS:.c=.o}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} ${HEADER}
				${LIB} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re