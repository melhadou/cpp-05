#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool is_signed;
  const int signGrade;
  const int execGrade;

  AForm();

public:
  AForm(std::string name, const int signGrade, const int execGrade);
  AForm &operator=(AForm const &rhs);
  AForm(AForm const &rhs);
  virtual ~AForm();

  /* Grade Too High Exception */
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  /* Grade Too Low Exception */
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSigned : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  void beSigned(Bureaucrat &bureau);
  virtual void execute(Bureaucrat const &executor) const = 0;

  int getSignGrade() const;
  int getExecGrade() const;
  std::string const &getName() const;
  bool getIsSigned() const;
};

std::ostream &operator<<(std::ostream &ostream, AForm &instance);
