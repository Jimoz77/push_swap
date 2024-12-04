FILE	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c\
			ft_tolower.c ft_toupper.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
			ft_strjoin.c ft_strmapi.c ft_memchr.c ft_split.c ft_itoa.c ft_putendl_fd.c ft_striteri.c\
			ft_putchar.c ft_putstr.c ft_itoa_base.c ft_unitoa.c ft_itoa_base_printf.c ft_intlen.c\

BFILE =		ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

OBJS	=	$(FILE:.c=.o)

OBJS_BONUS = $(BFILE:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -I.
LIBC	=	ar rcs
NAME	=	libft.a

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
