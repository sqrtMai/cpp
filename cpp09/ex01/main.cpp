#include "RPN.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./RPN \"[args]\"" << std::endl;
		return 1;
	}

	RPN rpn;
	return rpn.execute(argv);

}
