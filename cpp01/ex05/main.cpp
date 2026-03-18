#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	Harl harl;
	std::string str(argv[1]);
	harl.complain(str);
	harl.~Harl();
}
