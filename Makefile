CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -std=c99 -g3
SOURCES	= src/substr.c
OBJS= $(SOURCES:.c=.o)
NAME 	=	libsubstr.a
BIN_TEST = test/test

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	 $(CC) -o $@ -c $< $(FLAGS)

test: $(NAME)
	$(CC) $(FLAGS) -Isrc test/main.c -L. -lsubstr -o $(BIN_TEST)
	exec $(BIN_TEST)

clean:
	@rm -rf $(OBJS) $(NAME) $(BIN_TEST)

.PHONY: test
