NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILER = c++

CFILES = megaphone.cpp

O_DIR =  objdir
OFILES = $(CFILES:%.cpp=$(O_DIR)/%.o)

D_DIR = depdir
DFILES = $(CFILES:%.cpp=$(D_DIR)/%.d)

all: $(NAME)

-include $(DFILES)

$(NAME): $(OFILES)
	$(COMPILER) $(FLAGS) $(OFILES) -o $(NAME)
	@echo "\033[33m** Program created **\033[0m"

$(O_DIR) $(D_DIR):
	mkdir -p $@

$(O_DIR)/%.o: %.cpp | $(O_DIR) $(D_DIR)
	$(COMPILER) $(FLAGS) -MMD -MP -MF $(D_DIR)/$*.d -c $< -o $@

clean:
	rm -rf $(O_DIR) $(D_DIR)
	@echo "\033[33m** Object/Dependency files deleted **\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m** Program deleted **\033[0m"

re: fclean all

.SECONDARY: $(OFILES) $(DFILES)

.PHONY: all clean fclean re

.SILENT: