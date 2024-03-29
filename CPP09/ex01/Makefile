# Configuration of paths
SRCDIR := src
OBJDIR := obj
INCDIR := .

# Name of the final executable
NAME = RPN

# Decide whether the commands will be shwon or not
VERBOSE = FALSE

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard $(SRCDIR)/*.cpp)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Name the compiler & flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS += -iquote$(INCDIR)

# rules for compile
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(HIDE)$(CC) $(CFLAGS) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)

clean		:
	$(HIDE)rm -rf $(OBJDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME)

re			: fclean all

print		: 
	@echo $(OBJS)

run			: all
	./$(NAME)

# Create  repo of objects!
buildrepo	:
	$(HIDE)$(call make-repo)

define make-repo
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)for dir in $(DIRS); \
   	do \
	mkdir -p $(OBJDIR)/$$dir; \
   	done
endef


# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

ifeq ($(VERBOSE),TRUE)
    HIDE =  
else
    HIDE = @
endif

-include $(OBJS:)