NAME = call_me_maybe
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILER = c++
HEADER = classes.hpp

#S_DIR = src
CFILES = 

#O_DIR = objdir
OFILES = $(CFILES:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(COMPILER) $(FLAGS) $(OFILES) -o $(NAME)
	@echo "\033[33m** Program created **\033[0m"

#$(O_DIR):
#	mkdir -p $@

$%.o: %.cpp $(HEADER)
	$(COMPILER) $(FLAGS) -c -Iinc $< -o $@

clean:
	rm -f $(OFILES)
	@echo "\033[33m** Object files deleted **\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m** Program deleted **\033[0m"

re: fclean all

.SECONDARY: $(OFILES)

.PHONY: all clean fclean re

.SILENT: