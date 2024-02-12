NAME 	= philo
SRC 	= src/main.c src/philosophers.c src/utils.c src/init.c src/parsing.c
OBJ 	= ${SRC:.c=.o}

CC 		= cc
RM 		= rm -f
CFLAGS	= -g -Wall -Wextra -Werror -g
INCLUDE = -I include

GREEN	= \033[38;5;47m
YELLOW	= \033[38;5;226m
RED		= \033[38;5;196m
END 	= \033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "${GREEN}compiling${END}: $<"

${NAME}: ${OBJ}
	@${CC} ${OBJ} -o ${NAME}
	@echo "${GREEN}${NAME} created${END}"

all: ${NAME}

clean:
	@${RM} ${OBJ}
	@echo "${RED}cleaning objects${END}"

fclean: clean
	@${RM} ${NAME}
	@echo "${RED}${NAME} deleted${END}"

re: fclean all

.PHONY: all clean fclean re