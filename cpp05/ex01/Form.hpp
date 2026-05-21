#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool firmado;
	const int gradeSign;
	const int gradeExec;
public:
	Form(const std::string name, const int gradeSign, const int gradeExec);
	Form(const Form& other);
	Form& operator =(const Form& other);
	~Form();

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	void beSigned(Bureaucrat &someone);
	const std::string& getName();
	bool		   isSigned();
	const int&		   getGradeSign();
	const int&		   getGradeExec();
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif
