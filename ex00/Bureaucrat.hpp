#pragma once

#include <iostream>

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

  /* Getters */
  std::string getName(void);
  int getGrade(void);
};

/* insertion operator */
std::ostream &operator<<(std::ostream &ostream, Bureaucrat &other);
