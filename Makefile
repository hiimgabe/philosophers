NAME 	= philo
SRC 	= src/main.c src/utils.c src/init.c src/parsing.c src/routine.c src/monitor.c src/forks.c src/status.c
OBJ 	= ${SRC:.c=.o}

CC 		= cc
RM 		= rm -f
CFLAGS	= -Wall -Wextra -Werror -pthread -fsanitize=thread -g -D DEBUG=true
INCLUDE = -I include
LIBS	= -L/usr/lib/gcc/x86_64-linux-gnu/11 -ltsan

GREEN	= \033[38;5;47m
YELLOW	= \033[38;5;226m
RED		= \033[38;5;196m
END 	= \033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "${GREEN}compiling${END}: $<"

${NAME}: ${OBJ}
	@${CC} ${OBJ} ${LIBS} -o ${NAME}
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