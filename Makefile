SRC = push_swap.c parseur/parseur.c utils/instruction.c utils/utils.c utils/utils2.c utils/free.c solver/solver.c solver/up_value.c

BONUS_SRC = bonus/checker.c parseur/parseur.c utils/utils.c utils/utils2.c utils/free.c utils/get_next_line/get_next_line.c \
						utils/get_next_line/get_next_line_utils.c utils/instruction.c

NAME = push_swap

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

Fother = -no-pie

OBJ = ${SRC:.c=.o}

BONUS_OBJ = ${BONUS_SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C utils/ft_printf
	make -C utils/libft
	${CC} ${FLAGS} ${OBJ} -o push_swap -L utils/ft_printf -lftprintf -L utils/libft -lft

bonus : ${BONUS_OBJ}
	make -C utils/libft
	make -C utils/ft_printf
	${CC} ${FLAGS} ${BONUS_OBJ} -o checker -L utils/libft -lft -L utils/ft_printf -lftprintf

all : ${NAME}

clean :
	make clean -C utils/ft_printf
	make clean -C utils/libft
	${RM} ${OBJ} ${BONUS_OBJ}

fclean : clean
	make fclean -C utils/ft_printf
	make fclean -C utils/libft
	${RM} ${NAME} checker

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

.PHONY: all clean fclean re bonus party