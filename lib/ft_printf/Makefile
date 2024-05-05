SRCS			= 	ft_itoa_signed.c \
					ft_itoa_unsigned.c \
					ft_functions.c \
					ft_printf.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
