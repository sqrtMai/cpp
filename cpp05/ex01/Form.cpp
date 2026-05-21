#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : name(name), firmado(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

void Form::beSigned(Bureaucrat &someone)
{
	if (someone.getGrade() > this->gradeSign)
		throw Form::GradeTooLowException();
	else
		this->firmado = true;
}

const std::string& Form::getName()
{
	return this->name;
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "Something went wrong with Bureaucrat's grade (Grade too high)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Something went wrong with Bureaucrat's grade (Grade too low)";
}

std::ostream& operator<<(std::ostream& out, Form& b)
{
	out << "Form: " << b.getName() << std::endl;
	out << "Is form signed? : " << b.isSigned() << std::endl;
	out << "Grade to sign required: " << b.getGradeSign() << std::endl;
	out << "Grade to execute required: " << b.getGradeExec() << std::endl;
	return out;
}

bool Form::isSigned()
{
	return this->firmado;
}

const int& Form::getGradeExec()
{
	return this->gradeExec;
}

const int& Form::getGradeSign()
{
	return this->gradeSign;
}
