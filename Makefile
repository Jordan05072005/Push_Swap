SRC = push_swap.c parseur/parseur.c utils/instruction.c utils/utils.c utils/utils2.c utils/free.c solver/solver.c solver/up_value.c

NAME = push_swap

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	make -C utils/ft_printf
	make -C utils/libft
	${CC} ${FLAGS} ${OBJ} -o push_swap -g -L utils/ft_printf -lftprintf -L utils/libft -lft

all : ${NAME}

clean :
	make clean -C utils/ft_printf
	make clean -C utils/libft
	${RM} ${OBJ}

fclean : clean
	make fclean -C utils/ft_printf
	make fclean -C utils/libft
	${RM} ${NAME}

re : fclean all clean

party:
					@clear
					@echo "\n\n\033[35m♪┏(・o･)┛♪ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					@clear
					@echo "\n\n\033[1;33m♪┗(・o･)┓♪ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					@clear
					@echo "\n\n\033[35m♪┏(・o･)┛♪ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					@clear
					@echo "\n\n\033[1;33m♪┗(・o･)┓⁠♪ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					@clear
					@echo "\n\n\033[35m♪~~(･o・ )┛ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					@clear
					@echo "\n\n\033[1;33m♪┗( ·o･)~~ \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 1
					clear
					@echo "\n\n\033[1;37m♪( ◦o◦) \033[1;31m┬⁠─⁠┬⁠\n\n"
					@sleep 3
					@clear
					@echo "\n\n\033[1;31m(⁠┛⁠◉⁠Д⁠◉⁠)⁠┛⁠彡⁠┻⁠━⁠┻\n\n"
					@sleep 2.5
					@clear
					@echo "\n\n\033[1;36mᕦ⁠(⁠ಠ⁠_⁠ಠ⁠)⁠ᕤ⁠\n\n"

.PHONY: all clean fclean re party