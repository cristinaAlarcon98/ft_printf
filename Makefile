NAME = libftprintf.a
EXEC = libfttest
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_printf \
	ft_printf_utils

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $@ $^

$(EXEC): $(NAME)
	@$(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)

testmain: $(EXEC)
	./$(EXEC)
	

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re