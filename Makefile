######################################################################################
## ARGUMENTS

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror


######################################################################################
## SOURCES

SRC	=	main.c \
		algo_simple_utils.c \
		algo_simple.c \
		algo_medium.c \
		algo_complexe.c \
		algo_adaptive.c \
		benchmark_mode.c \
		compute_disorder.c \
		find_index.c \
		ft_error.c \
		ft_split.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		parsing_utils.c \
		parsing.c \
		lst_utils.c \
		ft_printf_utils.c \
		ft_printf.c \

OBJ = ${SRC:.c=.o}


######################################################################################
## RULES

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re