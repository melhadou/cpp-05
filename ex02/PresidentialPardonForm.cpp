#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &rhs)
    : AForm(rhs.getName(), 25, 5), target(rhs.target) {
  if (this != &rhs)
    *this = rhs;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
  if (this != &rhs)
    this->target = rhs.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  // check requirements
  if (!this->getIsSigned())
    throw PresidentialPardonForm::FormNotSigned();
  if (executor.getGrade() > this->getExecGrade())
    throw PresidentialPardonForm::GradeTooLowException();

  std::cout << this->target << "has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
