HEADER	= -I libft.h

NAME	= libft.a

SRCS	=	ft_atoi.c		ft_isdigit.c	ft_memmove.c	ft_strlen.c\
			ft_bzero.c		ft_isprint.c	ft_memset.c		ft_strncmp.c\
			ft_calloc.c		ft_memccpy.c	ft_strchr.c		ft_strnstr.c\
			ft_isalnum.c	ft_memchr.c		ft_strdup.c		ft_strrchr.c\
			ft_isalpha.c	ft_memcmp.c		ft_strlcat.c	ft_tolower.c\
			ft_isascii.c	ft_memcpy.c		ft_strlcpy.c	ft_toupper.c\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_itoa.c\
			ft_split.c		ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	get_next_line.c ft_atoi_base.c

BONUS	=	ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c	ft_lstlast.c\
			ft_lstadd_back.c	ft_lstdelone.c			ft_lstclear.c	ft_lstiter.c

OBJS 	= $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

AR 		= ar rcs

CC		= gcc

FLAGS 	= -Wall -Wextra -Werror

RM		= rm -f



.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(HEADER)

all:	$(NAME)

$(NAME):	$(OBJS) 
		$(AR) $(NAME) $?
	
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

bonus: 	$(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONI: all clean fclean re bonus

