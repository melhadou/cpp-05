#pragma once

#include "AForm.hpp"
#include "string"

class Intern {
private:
  // defining a member function pointer t_form. ::*
  typedef AForm *(Intern::*t_form)(std::string target);
  std::string formTypes[3];

  t_form formPtrs[3];

  AForm *PresidentialForm(std::string target);
  AForm *ShrubberyForm(std::string target);
  AForm *RobotomyForm(std::string target);

public:
  Intern();
  Intern(Intern const &rhs);
  Intern &operator=(Intern const &rhs);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);
};
