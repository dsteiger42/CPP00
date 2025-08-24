NAME = phonebook

SRCS = src/main.cpp src/PhoneBook.cpp src/Contact.cpp
CC = clang++
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
