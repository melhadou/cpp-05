#pragma once

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
private:
  std::string target;
  PresidentialPardonForm();

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm const &rhs);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
  ~PresidentialPardonForm();

  void execute(const Bureaucrat &executor) const; // Override
};
