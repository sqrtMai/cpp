#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	this->target = other.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat &someone)
{
	if (someone.getGrade() > this->getGradeSign() && someone.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		this->beSigned(someone);

	std::ofstream file((target + "_shrubbery").c_str());
	file << "   /\\\n";
	file << "  /**\\\n";
	file << " /****\\\n";
	file << "/******\\\n";
	file << "  |||\n";
	file << "  |||\n";
}

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& b)
{
	out << "AForm: " << b.getName() << std::endl;
	out << "Is Aform signed? : " << b.isSigned() << std::endl;
	out << "Grade to sign required: " << b.getGradeSign() << std::endl;
	out << "Grade to execute required: " << b.getGradeExec() << std::endl;
	return out;
}
