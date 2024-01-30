#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
  try {
    Intern mohamed;

    AForm *shrubby = mohamed.makeForm("Shrubbery", "ahmed");
    AForm *prsedent = mohamed.makeForm("Presidential Pardon", "said");
    AForm *robotomy = mohamed.makeForm("Robotomy Request", "mosa");
    AForm *wrong = mohamed.makeForm("not a form", "notFound");

    std::cout << "-------------------------" << std::endl;
    std::cout << shrubby->getName() << std::endl;
    std::cout << *shrubby << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << prsedent->getName() << std::endl;
    std::cout << *prsedent << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << robotomy->getName() << std::endl;
    std::cout << *robotomy << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << wrong << std::endl;

    delete robotomy;
    delete prsedent;
    delete shrubby;

    return 0;
  } catch (std::exception &e) {

    std::cerr << e.what() << std::endl;
  }

  return 0;
}
