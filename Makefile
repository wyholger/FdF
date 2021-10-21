SRCS		=	src/control_2.c		src/map.c		src/rotate.c				src/utilit_2.c\
				src/color.c			src/draw.c		src/matrix_operation.c		src/window.c\
				src/control.c		src/main.c		src/matrix_operation_2.c	src/utilit.c\
				src/read.c
OBJS		= ${SRCS:.c=.o}
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= fdf

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -Ofast

all:	$(NAME)

$(NAME):	$(OBJS)
		make bonus -C libft
		$(CC) $(FLAGS) -Llibft -lft -lmlx -lm -Ofast -framework OpenGL -framework AppKit $(SRCS) -o fdf

clean:	
		${RM} ${OBJS} 
		$(MAKE) clean -C ./libft 

fclean:		clean
		${RM} ${NAME}
		$(MAKE) fclean -C ./libft 

re:		fclean all clean 