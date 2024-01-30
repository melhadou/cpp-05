#include "Form.hpp"

/*
 * Implementation of excpetion what function.
 * What func returns a string to describe the excpetion
 * */
const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}
/*
 *
 * */

Form::Form(const std::string name, const int signGrade, const int execGrade)
    : name(name), signGrade(signGrade), execGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->is_signed = false;
}

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs)
    this->is_signed = rhs.is_signed;
  return *this;
}

// copy constructor
Form::Form(const Form &rhs)
    : name(rhs.name), is_signed(rhs.is_signed), signGrade(rhs.signGrade),
      execGrade(rhs.execGrade) {}

Form::~Form() {}

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->signGrade)
    throw Form::GradeTooLowException();
  this->is_signed = true;
}

// Implement Const Getters
std::string const &Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->is_signed; }
int Form::getSignGrade() const { return this->signGrade; }
int Form::getExecGrade() const { return this->execGrade; }

std::ostream &operator<<(std::ostream &ostream, Form &instance) {
  return ostream << "Form Name: " << instance.getName()
                 << " Sign Grade: " << instance.getSignGrade()
                 << " Exec Grade: " << instance.getExecGrade()
                 << " Is Signed: " << instance.getIsSigned();
}
