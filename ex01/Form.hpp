#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool is_signed;
  const int signGrade;
  const int execGrade;

  Form();

public:
  Form(std::string name, const int signGrade, const int execGrade);
  Form &operator=(Form const &rhs);
  Form(Form const &rhs);
  ~Form();

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

  void beSigned(Bureaucrat &bureau);

  int getSignGrade() const;
  int getExecGrade() const;
  std::string const &getName() const;
  bool getIsSigned() const;
};

std::ostream &operator<<(std::ostream &ostream, Form &instance);
