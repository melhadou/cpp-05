NAME = AFormExec
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFILES = main.cpp Bureaucrat.cpp AForm.cpp \
					 PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
CXXOBJ = $(CXXFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $(CXXOBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(CXXOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
