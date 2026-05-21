#ifndef PRESIDENTIAL_PARDON_HPP
#define PRESIDENTIAL_PARDON_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &someone) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif
