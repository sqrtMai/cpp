#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat const *Joe = new Bureaucrat("Joe", 2);
	Bureaucrat const *Low = new Bureaucrat("Low", 150);
	AForm  *Shrubbery = new ShrubberyCreationForm("Mai");
	 AForm  *Robotomy = new RobotomyRequestForm("Mai");
	 AForm  *Presidential = new PresidentialPardonForm("Mai");

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

	Joe->executeForm(*Shrubbery);
	Low->executeForm(*Shrubbery);
	Joe->executeForm(*Robotomy);
	Low->executeForm(*Robotomy);
	Joe->executeForm(*Presidential);
	Low->executeForm(*Presidential);


	Joe->signForm(*Shrubbery);
	Joe->signForm(*Robotomy);
	Joe->signForm(*Presidential);

	Low->signForm(*Shrubbery);
	Low->signForm(*Robotomy);
	Low->signForm(*Presidential);


	Joe->executeForm(*Shrubbery);
	Low->executeForm(*Shrubbery);
	Joe->executeForm(*Robotomy);
	Low->executeForm(*Robotomy);
	Joe->executeForm(*Presidential);
	Low->executeForm(*Presidential);


	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

	delete Shrubbery;
	delete Robotomy;
	delete Presidential;
	delete Joe;
	delete Low;


}
