FILE	=	./instructions_folder/*.c ./utils_folder/*.c ./ft_printf/*.c ./ft_printf/libft/*.c

OBJS	=	$(FILE:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:		
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re



#NON FONCTIONNEL A CORRIGER !!!!!