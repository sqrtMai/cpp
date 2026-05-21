#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool firmado;
	const int gradeSign;
	const int gradeExec;
public:
	AForm(const std::string name, const int gradeSign, const int gradeExec);
	AForm(const AForm& other);
	AForm& operator =(const AForm& other);
	virtual ~AForm();

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

	class NoSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	void beSigned(Bureaucrat const &someone);
	const std::string& getName() const;
	bool	   		   isSigned() const;
	const int&		   getGradeSign() const;
	const int&		   getGradeExec() const;
	virtual void execute(Bureaucrat const &someone) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif
