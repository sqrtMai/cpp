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



std::vector<std::pair<int, int> >::iterator find_pair(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> >::iterator it, int level)
{
	for (; it != set.end(); ++it)
	{
		for ( std::vector<std::pair<int, int> >::iterator next = it + 1; next != set.end(); ++next)
		{
			if ((*it).second == (*next).second && (*next).second == level)
			{
				return (next);
			}
		}
	}
	return set.end();
}


int find_current_level(std::vector<std::pair<int, int> > &set)
{
	int level = -1;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second > level)
			level = set[i].second;
	}
	return level;
}

void swapBlock(std::vector<std::pair<int, int> >::iterator &first_pair, std::vector<std::pair<int, int> >::iterator &side_pair)
{
	int level = (*first_pair).second;
	int i = 0;


	while (level > 0)
	{
		std::swap(first_pair[i], side_pair[i]);
		i++;
		level--;
	}
}


// size_t jacobsthal(size_t n)
// {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }



std::vector<std::pair<int, int> >::iterator findBigger(int nb, std::vector<std::pair<int, int> > &set, int level)
{
	for (size_t i = 0; i + (size_t)level < set.size(); i+=level)
	{
		if (nb < set[i].first)
			return set.begin() + i;
	}
	return set.end();
}


std::vector<std::pair<int, int> > setLevelBack(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &old, int pends_lvl)
{
	size_t j = 0;

	for (size_t i = 0; i < set.size(); i++)
	{
		for (size_t j = i; j < old.size(); j++)
		{
			if (old[j].first == set[i].first)
				set[i].second = old[j].second;
		}
	}
	return set;
}

std::vector<std::pair<int, int> > jsp(std::vector<std::pair<int, int> > &set, int level)
{
	int pends_lvl = level;
	level *= 2;
	std::vector<std::pair<int, int> > temp;
	std::vector<std::pair<int, int> > old_smaller;
	std::vector<std::pair<int, int> >::iterator found;
	size_t pos;

	for (size_t i = 0; i < set.size(); i += pends_lvl)
	{
		if (set[i].second == pends_lvl)
		{
			//std::cout << set[i].first << std::endl;
			for (int j = 0; j < pends_lvl; j++)
			{
				temp.push_back(set[i + j]);
			}
			old_smaller.push_back(set[i]);
			temp[0].second = level;
			for (int j = 0; j < pends_lvl; j++)
			{
				set.erase(set.begin() + i);
			}
			found = findBigger(temp[0].first, set, pends_lvl);
			pos =  found - set.begin();
			set.insert(
					found,
					temp.begin(),
					temp.end());
				//if (i + j < set.size())
		}
		temp.clear();
		set = setLevelBack(set, old_smaller, pends_lvl);
	}
	return set;
}

std::vector<std::pair<int, int> > vAlgo(std::vector<std::pair<int, int> > &set)
{

	std::vector<std::pair<int, int> >::iterator first_pair;
	std::vector<std::pair<int, int> >::iterator side_pair;

	int level = find_current_level(set);

	for (size_t i = 0; i < set.size(); i += level)
	{
		if (i + level < set.size())
		{
			std::vector<std::pair<int, int> >::iterator first_pair = set.begin() + i;
			side_pair = find_pair(set, set.begin() + i, level); //ça peut juste être set.begin() + i + level;
			if (side_pair == set.end())
				break;

			if (level >= set.size() / 2)
			{
				if ((*first_pair).first > (*side_pair).first)
				{
					swapBlock(first_pair, side_pair);
				}
				return set;
			}
			if ((*first_pair).first < (*side_pair).first)
			{
				swapBlock(first_pair, side_pair);
			}
			if ((*first_pair).first < (*side_pair).first)
			{
				(*side_pair).second *= 2;
				i += level;
			}
			else
			{
				(*first_pair).second *= 2;
				i += level;
			}
		}
	}

	for (size_t i = 0; i < set.size(); i++)
	{
		std::cout << "(" << set[i].first << ", " << set[i].second << ") - ";
	}
	std::cout << std::endl;


	set = vAlgo(set);
	return set;
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

	std::vector<std::pair<int, int> > input;

	for (size_t i = 1; argv[i]; i++)
	{
		std::pair<int, int> p;

		p.first = static_cast<int>(strtod(argv[i], NULL));
		p.second = 1;

		input.push_back(p);
	}

	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << "(" << input[i].first << ", " << input[i].second << ") - ";
	}
	std::cout << std::endl;

	input = vAlgo(input);
	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << "(" << input[i].first << ", " << input[i].second << ") - ";
	}
	std::cout << std::endl;
	input = jsp(input, 2);
	input = jsp(input, 1);

	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << "(" << input[i].first << ", " << input[i].second << ") - ";
	}
	std::cout << std::endl;

}




