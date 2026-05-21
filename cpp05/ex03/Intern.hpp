#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm *makeForm(std::string name, std::string target);
	AForm *Shrubbery(std::string target);
	AForm *Robotomy(std::string target);
	AForm *Presidential(std::string target);
};

#endif
