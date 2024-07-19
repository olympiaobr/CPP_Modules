CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: megaphone

megaphone: megaphone.o
	$(CC) $(CFLAGS) -o megaphone megaphone.o

megaphone.o: megaphone.cpp
	$(CC) $(CFLAGS) -c megaphone.cpp

clean:
	rm -f *.o

fclean: clean
	rm -f megaphone

re: fclean all

.PHONY: all clean fclean re

