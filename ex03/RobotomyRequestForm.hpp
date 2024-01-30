#pragma once

#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
private:
  std::string target;
  RobotomyRequestForm();

public:
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(RobotomyRequestForm const &rhs);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const &executor) const;
};
