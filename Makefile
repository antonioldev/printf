NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.$(DEPS)
SRC = 	ft_printf.c ft_put*.c ft_utils.c
OBJ = $(SRC:.c=.o)
DEPS = ft_printf.h

RM = rm -f

all: $(NAME)

test:
	cc -Wall -Wextra -Werror -g test.c ft_printf.c ft_put*.c ft_utils.c
	$(RM) $(OBJ)

$(NAME) : $(OBJ) 
	ar  rc $@ $^

$(OBJ) : 
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
