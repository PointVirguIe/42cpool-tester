.PHONY: clean fclean re all

NAME	?= 42pool_test
CC 		?= gcc
CFLAGS 	?= -Wall -Wextra -Werror
SRCS 	= $(shell find ./srcs -name "*.c")
OBJS 	= ${SRCS:.c=.o}

all:	$(NAME)

${NAME}: ${OBJS} Makefile
	${CC} ${CFLAGS} ${OBJS} -o ${@}

%.o: %.c
	${CC} ${CFLAGS} -c ${<} -o ${@}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re	:	fclean all
		make clean