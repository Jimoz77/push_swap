FILE	=	./instructions_folder/*.c ./utils_folder/*.c ./ft_printf/*.c ./ft_printf/libft/*.c 
MAIN	=	main.c
FILEB	=	./file_checker_bonus/gnl/get_next_line.c ./file_checker_bonus/gnl/get_next_line_utils.c

OBJS	=	$(FILE:.c=.o)

OBJSB	=	$(BONUSF:.c=.o) $(FILEB:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I. -I./file_checker_bonus/gnl -I./file_checker_bonus
NAME	=	push_swap
NAMEB	=	checker_bonus
BONUSF	=	./file_checker_bonus/checker_bonus.c

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(MAIN) $(FILE) -o $(NAME)

clean:		
			rm -f $(OBJS) $(OBJSB)

fclean:		clean
			rm -f $(NAME) $(NAMEB)

re:			fclean all

bonus:		$(NAMEB)

$(NAMEB):	$(OBJSB)
			$(CC) $(FLAGS) $(BONUSF) $(FILE) $(FILEB) -o $(NAMEB)

.PHONY:		all clean fclean re bonus