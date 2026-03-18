#include <iostream>
#include <string>


void changeBrain(std::string &brain)
{
	brain = "empty";
}

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << str << std::endl << *stringPTR << std::endl << stringREF << std::endl;


	stringREF = "HI THIS IS NOT BRAIN ANYMORE";

	std::cout << &str << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << str << std::endl << *stringPTR << std::endl << stringREF << std::endl;

	str = "BRAIN                 BRAIN";

	std::cout << &str << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << str << std::endl << *stringPTR << std::endl << stringREF << std::endl;

	*stringPTR = "WHAT AM I";

	std::cout << &str << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << str << std::endl << *stringPTR << std::endl << stringREF << std::endl;

	changeBrain(stringREF);

	std::cout << &str << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << str << std::endl << *stringPTR << std::endl << stringREF << std::endl;

	return 0;
}
