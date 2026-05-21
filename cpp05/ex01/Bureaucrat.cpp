#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::increment(void)
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrement(void)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooHighException();
	else
		grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Something went wrong incrementing Bureaucrat's grade (Grade too high)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Something went wrong incrementing Bureaucrat's grade (Grade too low)";
}

const std::string& Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr <<  this->getName() << " couldn't sign " << form.getName() << " beacause " << e.what() << '\n';
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}
