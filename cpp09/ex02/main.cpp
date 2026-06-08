#include "PmergeMe.hpp"

int check_args(char **args)
{
	double arg;
	char *end;

	for (int i = 1; args[i]; i++)
	{
		arg = strtod(args[i], &end);
		if (*end != 0 || arg < 0 || arg > __INT_MAX__)
		{
			std::cerr << "Error: invalid arguments" << std::endl;
			return 1;
		}
	}
	return 0;
}


std::vector<int> vAlgo(std::vector<int> input)
{
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;
	std::vector<int> losers;

	int remainer = -5;

	if (input.size() <= 1)
		return input;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (i + 1 != input.size())
		{
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
			i++;
		}
		else
			remainer = input[i];
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);

		winners.push_back(pairs[i].second);
		losers.push_back(pairs[i].first);
	}

	//winners = vAlgo(winners);

	for (size_t i = 0; i < losers.size(); i++)
		winners.push_back(losers[i]);

	for (size_t i = 0; i < winners.size(); i++)
	{
		std::cout << winners[i] << " - ";
	}
	std::cout << std::endl;
	(void)remainer;

	return winners;
}


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "./PmergeMe [args]" << std::endl;
		return 0;
	}
	if (check_args(argv))
		return 1;


	std::vector<int> input;

	for (int i = 1; argv[i]; i++)
	{
		input.push_back(static_cast<int>(strtod(argv[i], NULL)));
	}

	vAlgo(input);
}




