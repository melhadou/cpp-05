#pragma once
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;
  ShrubberyCreationForm(void);

public:
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;
};
