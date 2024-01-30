#include "AForm.hpp"

/*
 * Implementation of excpetion what function.
 * What func returns a string to describe the excpetion
 * */
const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char *AForm::FormNotSigned::what() const throw() {
  return "Form not signed.";
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
    : name(name), signGrade(signGrade), execGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    throw Bureaucrat::GradeTooLowException();
  // throw grade excpetion
  this->is_signed = false;
}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs)
    this->is_signed = rhs.is_signed;
  return *this;
}

// copy constructor
AForm::AForm(const AForm &rhs)
    : name(rhs.name), is_signed(rhs.is_signed), signGrade(rhs.signGrade),
      execGrade(rhs.execGrade) {}

AForm::~AForm() {
  std::cout << this->name << " Destructor Called" << std::endl;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->signGrade)
    throw AForm::GradeTooLowException();
  this->is_signed = true;
}

// Implement Const Getters
std::string const &AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->is_signed; }
int AForm::getSignGrade() const { return this->signGrade; }
int AForm::getExecGrade() const { return this->execGrade; }

std::ostream &operator<<(std::ostream &ostream, AForm &instance) {
  return ostream << "AForm Name: " << instance.getName()
                 << " Sign Grade: " << instance.getSignGrade()
                 << " Exec Grade: " << instance.getExecGrade()
                 << " Is Signed: " << instance.getIsSigned();
}
