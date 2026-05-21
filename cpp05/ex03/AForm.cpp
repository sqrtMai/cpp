#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : name(name), firmado(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name),
								firmado(other.firmado),
								gradeSign(other.gradeSign),
								gradeExec(other.gradeExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}


AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator =(const AForm &other)
{
	std::cout << "AForm copy assignation called" << std::endl;
	if (this == &other)
		return *this;
	this->firmado = other.firmado;
	return *this;
}

void AForm::beSigned(Bureaucrat &someone)
{
	if (someone.getGrade() > this->gradeSign)
		throw AForm::GradeTooLowException();
	else
		this->firmado = true;
}

const std::string& AForm::getName()
{
	return this->name;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Something went wrong with Bureaucrat's grade (Grade too high)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Something went wrong with Bureaucrat's grade (Grade too low)";
}

std::ostream& operator<<(std::ostream& out, AForm& b)
{
	out << "AForm: " << b.getName() << std::endl;
	out << "Is Aform signed? : " << b.isSigned() << std::endl;
	out << "Grade to sign required: " << b.getGradeSign() << std::endl;
	out << "Grade to execute required: " << b.getGradeExec() << std::endl;
	return out;
}

bool AForm::isSigned()
{
	return this->firmado;
}

const int& AForm::getGradeExec()
{
	return this->gradeExec;
}

const int& AForm::getGradeSign()
{
	return this->gradeSign;
}
