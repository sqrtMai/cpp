#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator =(const Bureaucrat &other);
	~Bureaucrat();

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

	const std::string&	 getName(void) const;
	int					 getGrade(void) const;
	void				 increment(void);
	void				 decrement(void);
	void				 signForm(AForm &form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
