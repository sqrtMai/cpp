#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	(void)argc;
	std::string param(argv[1]);
	ScalarConverter::convert(param);
}
