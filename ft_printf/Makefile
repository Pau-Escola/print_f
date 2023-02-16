NAME = libftprintf.a


SRCS = printf.c,  print_str.c, print_num.c, print_char.c \

INCLUDE = libftprintf.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${INCLUDE} Makefile
			@echo " ◎ Compiling   >   $<"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS} $(INCLUDE)
				@ar -rsc ${NAME} ${OBJS}
				@echo "\n Created $(NAME) ✓ \n"

all:	${NAME}

clean:
			@${RM} ${OBJS} 
			@echo "\n ◎ All objects cleaned successfully ◎ \n"

fclean:
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@${RM} bonus
			@echo "\n ◎ All objects and executable cleaned successfully ◎ \n"

re: fclean all

.PHONY: all clean fclean re
