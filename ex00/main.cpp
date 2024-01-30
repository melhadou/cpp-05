#include "Bureaucrat.hpp"

int main(void) {
  // testing the Bureaucrat
  // std::cout << mohamed << std::endl;
  try {
    Bureaucrat mohamed("Mohamed", 149);

    std::cout << mohamed.getName() << std::endl;
    std::cout << mohamed.getGrade() << std::endl;

    // testing the GradeTooHighException
    mohamed.increment();
    // testing the GradeTooLowException
    mohamed.decrement();

    std::cout << mohamed.getName() << std::endl;
    std::cout << mohamed.getGrade() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Error: Grade too low ->" << std::endl;
    std::cerr << "\t" << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Error: Grade too high -> " << std::endl;
    std::cerr << "\t" << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: some other type of exception" << std::endl;
    std::cerr << "\t" << e.what() << std::endl;
  }
  return 0;
}
