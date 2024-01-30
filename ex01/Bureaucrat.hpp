#pragma once

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat {
private:
  const std::string name;
  int grade;

  Bureaucrat(void);

public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat(void);

  /* Grade Too High Exception */
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; };
  };

  /* Grade Too Low Exception */
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; };
  };

  /* Utils Functions */
  void increment(void);
  void decrement(void);

  void signForm(Form &form);

  /* Getters */
  std::string const &getName(void) const;
  int getGrade(void) const;
};

/* insertion operator */
std::ostream &operator<<(std::ostream &ostream, Bureaucrat &other);
