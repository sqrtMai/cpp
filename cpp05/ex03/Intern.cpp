#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm *Intern::Shrubbery(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

AForm *Intern::Robotomy(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm *Intern::Presidential(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	return form;
}


AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*func[3])(std::string target) = {
		&Intern::Shrubbery,
		&Intern::Robotomy,
		&Intern::Presidential};
	for (int i = 0; i < 3; i++)
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*func[i])(target);
		}
	std::cout << "'" << name << "' doesn't exist" << std::endl;
	return NULL;
}
