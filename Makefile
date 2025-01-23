CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
NAME = push_swap
NAMEB = checker_igomez
PRINTF = printf/libftprintf.a

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
      utils_push3.c \
      utils.c \
      utils2.c \
      utils3.c \

SRCB =      check_gnl_bonus.c \
            check_gnl_utils_bonus.c \
            check_main_bonus.c \
            

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

$(NAME): $(OBJ)  $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(PRINTF)

bonus: $(OBJ) $(OBJB)
	$(CC) -o $(NAMEB) $(OBJB) $(PRINTF)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJB)

fclean:
	rm -rf $(NAME) $(NAMEB) $(OBJ) $(OBJB) 

re: clean all

.PHONY: all clean fclean re
