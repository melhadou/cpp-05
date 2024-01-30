#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
    : AForm(rhs.getName(), 145, 137), target(rhs.target) {
  if (this != &rhs)
    *this = rhs;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    this->target = rhs.target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned())
    throw ShrubberyCreationForm::FormNotSigned();
  if (executor.getGrade() > this->getExecGrade())
    throw ShrubberyCreationForm::GradeTooLowException();

  // creating the trarget_shrubbery file
  std::string fileName = this->target + std::string("_shrubbery");
  std::ofstream fileHandler(fileName.c_str());
  fileHandler << "        _-_" << std::endl;
  fileHandler << "     /~~   ~~\\" << std::endl;
  fileHandler << "  /~~         ~~\\" << std::endl;
  fileHandler << " {               }" << std::endl;
  fileHandler << "  \\  _-     -_  /" << std::endl;
  fileHandler << "    ~  \\ //  ~" << std::endl;
  fileHandler << " _- -   | | _- _" << std::endl;
  fileHandler << "   _ -  | |   -_" << std::endl;
  fileHandler << "       // \\" << std::endl;
  fileHandler.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
