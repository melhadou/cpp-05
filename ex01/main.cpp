#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Form form("mohamed", 10, 30);
    Bureaucrat boss("boss", 5);

    boss.signForm(form);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
