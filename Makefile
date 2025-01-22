CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
NAME = push_swap
LIBFT = printf/libftprintf.a

SRC = main.c \
      ord1.c \
      ord2.c \
      ord3.c \
      prints_push.c \
      utils_calc.c \
      utils_calc2.c \
      utils_err.c \
      utils_err2.c \
      utils_push.c \
      utils_push2.c \
      utils.c \
      utils2.c \
      utils3.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)  $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ) 

re: clean all

.PHONY: all clean fclean re
