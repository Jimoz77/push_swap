FILE	=	main.c instructions.c utils.c

OBJS	=	$(FILE:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I.
LIBC	=	ar rcs
NAME	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
			${LIBC} $(NAME) $(OBJS)

clean:		
			rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

bonus:		$(OBJS) $(OBJS_BONUS)
			$(LIBC)	$(NAME) $(OBJS_BONUS)

.PHONY:		all clean fclean re bonus