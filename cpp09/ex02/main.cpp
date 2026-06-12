#include "PmergeMe.hpp"



int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cout << "./PmergeMe [args]" << std::endl;
		return 0;
	}

	PmergeMe merge;

	return merge.start(argv);
}
