#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat first("Joe", 2);
	first.getName();
	first.getGrade();
	std::cout << first << std::endl;
	first.increment();
	std::cout << first << std::endl;
	first.decrement();
	std::cout << first << std::endl;
	first.increment();
	try
	{
		first.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat max("Jay", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat max("Jay", 150 + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	Bureaucrat copy(first);
	Bureaucrat copy2 = copy;

	std::cout << "copy = " << copy << std::endl;
	std::cout << "copy2 = " << copy << std::endl;

}
