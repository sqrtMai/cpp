#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat first("Joe", 2);
	Bureaucrat second("Céléstin", 150);
	std::cout << first << std::endl;
	Form form("bancs anti sdf", 3, 3);
	form.isSigned();
	form.getGradeExec();
	form.getGradeSign();
	first.signForm(form);
	second.signForm(form);

}
