#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Bureaucrat bureau("mohamed", 5);

    ShrubberyCreationForm shrubby("shrubby");
    RobotomyRequestForm robote("robot");
    PresidentialPardonForm presedent("Presid");

    std::cout << "------------------------------------------------"
              << std::endl;

    bureau.signForm(shrubby);
    // shrubby.beSigned(bureau);
    std::cout << shrubby << std::endl;
    bureau.executeForm(shrubby);

    std::cout << "------------------------------------------------"
              << std::endl;

    bureau.signForm(robote);
    std::cout << robote << std::endl;
    bureau.executeForm(robote);

    std::cout << "------------------------------------------------"
              << std::endl;

    // bureau.signForm(presedent);
    presedent.beSigned(bureau);
    std::cout << presedent << std::endl;
    bureau.executeForm(presedent);

    std::cout << "------------------------------------------------"
              << std::endl;

  } catch (std::exception &e) {

    std::cerr << e.what() << std::endl;
  }

  return 0;
}
