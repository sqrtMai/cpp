#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


int main(void)
{
	Intern Joe;
	AForm *form = Joe.makeForm("test", "sdf");
	AForm *form2 = Joe.makeForm("shrubbery creation", "sdf");
	(void)form;
	delete form2;
	return 0;
}
