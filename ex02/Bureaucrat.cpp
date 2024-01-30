#include "Bureaucrat.hpp"
#include <iostream>

/* Constrators */
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs)
    this->grade = rhs.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  // desctructor
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << *this << " signed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << this->name << " coulnd't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

/* Execute Form */
void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << "."
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << this->getName() << " couldn't execute " << form.getName()
              << "." << std::endl;
  }
}

/* Getters */
std::string const &Bureaucrat::getName(void) const { return this->name; }
int Bureaucrat::getGrade(void) const { return this->grade; }

/* Utils */
void Bureaucrat::increment(void) {
  if (this->grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decrement(void) {
  if (this->grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade++;
}

/* Overloading the insertion operator */
std::ostream &operator<<(std::ostream &ostream, Bureaucrat &other) {
  return ostream << other.getName() << ", bureaucrat grade " << other.getGrade()
                 << ".";
}
