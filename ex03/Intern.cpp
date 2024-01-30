#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
  // Initializing form types;
  this->formTypes[0] = "Presidential Pardon";
  this->formTypes[1] = "Shrubbery";
  this->formTypes[2] = "Robotomy Request";

  this->formPtrs[0] = &Intern::PresidentialForm;
  this->formPtrs[1] = &Intern::ShrubberyForm;
  this->formPtrs[2] = &Intern::RobotomyForm;
}

Intern::Intern(Intern const &rhs) { *this = rhs; }

Intern &Intern::operator=(Intern const &rhs) {
  if (this != &rhs) {
    this->formTypes[0] = rhs.formTypes[0];
    this->formTypes[1] = rhs.formTypes[1];
    this->formTypes[2] = rhs.formTypes[2];
  }
  return *this;
}

Intern::~Intern() {}

AForm *Intern::PresidentialForm(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::ShrubberyForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  for (int i = 0; i < 3; i++) {
    if (!name.compare(formTypes[i])) {
      std::cout << "Intern creates " << name << " ." << std::endl;
      return (this->*formPtrs[i])(target);
    }
  }
  std::cout << "Intern cant create this => " << name << " form." << std::endl;
  return NULL;
}
