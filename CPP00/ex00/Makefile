# Name of the final executable
NAME = megaphone

# Sources
SRCS = megaphone.cpp

all: $(NAME)

$(NAME):
    g++ -Wextra -Werror -Wall -std=c++98 $(SRCS) -o $(NAME)

run: all
	./megaphone && rm -rf megaphone