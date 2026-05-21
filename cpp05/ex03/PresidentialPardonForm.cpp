#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat &someone)
{
	if (someone.getGrade() > this->getGradeSign() && someone.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		this->beSigned(someone);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	this->target = other.target;
	return *this;
}

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm& b)
{
	out << "AForm: " << b.getName() << std::endl;
	out << "Is Aform signed? : " << b.isSigned() << std::endl;
	out << "Grade to sign required: " << b.getGradeSign() << std::endl;
	out << "Grade to execute required: " << b.getGradeExec() << std::endl;
	return out;
}
