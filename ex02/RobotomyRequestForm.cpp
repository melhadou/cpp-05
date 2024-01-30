#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
    : AForm(rhs.getName(), 72, 45), target(rhs.target) {
  if (this != &rhs)
    *this = rhs;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
  if (this != &rhs)
    this->target = rhs.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  std::cout << "robotimzed" << std::endl;

  // check requirements
  if (!this->getIsSigned())
    throw RobotomyRequestForm::FormNotSigned();
  if (executor.getGrade() > this->getExecGrade())
    throw RobotomyRequestForm::GradeTooLowException();

  srand(time(NULL));

  // making drilling noises
  std::cout << "drilling noises" << std::endl;

  if (rand() % 2)
    std::cout << this->target << " has been robotimzed successfully."
              << std::endl;
  else
    std::cout << this->target << " Robotomy failed." << std::endl;
  // start robotizing
}
