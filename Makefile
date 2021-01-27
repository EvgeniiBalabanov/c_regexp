.PHONY:	all clean fclean re

NAME		=	regexp.o

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes -I./libft/includes -I./list/includes -I./dlist/includes

# NAME_FILES	=	*.c

FILES		=	./src/*/*.c ./src/*.c

# OBJS		=	$(FILES:.c=.o)

all:		${NAME}

${NAME}:	#$(OBJS)
	gcc ${CFLAGS} -o ${NAME} ${FILES} ./libft/libft.o ./list/list.o ./dlist/dlist.o main.c
	# ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME}

re:	fclean all