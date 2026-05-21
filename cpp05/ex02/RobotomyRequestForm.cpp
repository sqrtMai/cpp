#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}


RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	this->target = other.target;
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const &someone) const
{
	if (!isSigned())
		throw AForm::NoSignedException();
	if (someone.getGrade() > this->getGradeSign() && someone.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << "Fzzzziouuuuuuuuuu" << std::endl;
	if (rand() % 2 == 1)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm& b)
{
	out << "AForm: " << b.getName() << std::endl;
	out << "Is Aform signed? : " << b.isSigned() << std::endl;
	out << "Grade to sign required: " << b.getGradeSign() << std::endl;
	out << "Grade to execute required: " << b.getGradeExec() << std::endl;
	return out;
}
