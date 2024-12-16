FILE	=	./instructions_folder/*.c ./utils_folder/*.c ./ft_printf/*.c ./ft_printf/libft/*.c 
MAIN	=	main.c
FILEB	=	./checker_folder/gnl/get_next_line.c ./checker_folder/gnl/get_next_line_utils.c ./checker_folder/gnl/get_next_line.h

OBJS	=	$(FILE:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	push_swap
NAMEB	=	checker
BONUSF	=	checker.c

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(MAIN) $(FILE) -o $(NAME)

clean:		
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME) $(NAMEB)

re:			fclean all

bonus:		
			$(CC) $(FLAGS) $(BONUSF) $(FILE) $(FILEB) -o $(NAMEB)

.PHONY:		all clean fclean re bonus



#NON FONCTIONNEL A CORRIGER !!!!!