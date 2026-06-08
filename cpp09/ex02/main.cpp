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

	winners = vAlgo(winners);

	std::vector<int>::iterator it;
	std::vector<int> jacob;
	std::vector<int> order;
	std::vector<bool> inserted(losers.size(), false);


	jacob.push_back(0);
	jacob.push_back(1);

	while (jacob.back() < losers.size())
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	for (size_t i = 0; i < losers.size(); i++)
	{
		it = std::lower_bound(winners.begin(), winners.end(), losers[i]);
		winners.insert(it, losers[i]);
	}













	if (remainer >= 0)
	{
		it = std::lower_bound(winners.begin(), winners.end(), remainer);
		winners.insert(it, remainer);
	}

	for (size_t i = 0; i < winners.size(); i++)
	{
		std::cout << winners[i] << " - ";
	}
	std::cout << std::endl;

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




