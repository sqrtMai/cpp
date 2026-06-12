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

std::vector<std::pair<int, int> >::iterator findBigger(int nb, std::vector<std::pair<int, int> > &set, int level, int winner)
{
	std::vector<size_t> mainIndex;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second >= level)
			mainIndex.push_back(i);
		if (set[i].first == winner)
			break ;
	}

	if (mainIndex.size() == 1)
		return set.begin() + mainIndex[0];

    size_t left = 0;
    size_t right = mainIndex.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (set[mainIndex[mid]].first < nb)
            left = mid + 1;
        else
            right = mid;
    }

    if (left >= mainIndex.size())
        return set.end();

    return set.begin() + mainIndex[left];
}




std::vector<std::pair<int, int> > setLevelBack(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &old, int pends_lvl)
{
	size_t j = 0;

	for (size_t i = 0; i < set.size(); i++)
	{
		for (size_t j = 0; j < old.size(); j++)
		{
			if (old[j].first == set[i].first)
				set[i].second = old[j].second;
		}
	}
	return set;
}


std::vector<int> jacob(size_t size)
{
	std::vector<long long> jacobstahl;
	std::vector<int> order;
	std::vector<int> current;

	jacobstahl.push_back(0);
	jacobstahl.push_back(1);

	for (int i = 2; jacobstahl[i - 1] < size; i++)
		jacobstahl.push_back(jacobstahl[i - 1] + 2 * jacobstahl[i - 2]);

	if (size > 2)
		jacobstahl.erase(jacobstahl.begin() + 2);


	int i;
	int prev;
	int curr;
	for (int i = 1; i < jacobstahl.size(); i++)
	{
		prev = jacobstahl[i - 1];
		curr = jacobstahl[i];
		if (i == 1)
		{
			order.push_back(prev);
			order.push_back(curr);
		}
		else
		{
			for (; curr > prev; curr--)
			{
				if (curr >= size)
					continue;
				order.push_back(curr);
			}
		}
	}

	while (size != order.size())
		order.erase(order.begin() + size);
	return order;
}

std::vector<std::pair<int, int> > jsp(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &remainer, int level)
{
	int pends_lvl = level / 2;

	std::cout << "MAIN CHAIN LEVEL = " << level << std::endl;
	// if  (level == 1)
	// 	return set;
	//level *= 2;
	std::vector<std::pair<int, int> > temp;
	std::vector<std::pair<int, int> > old_smaller;
	std::vector<std::pair<int, int> >::iterator found;
	std::vector<size_t> pends;

	size_t pos;


	if (remainer.size() >= 1)
	{
		old_smaller.push_back(remainer[0]);
		remainer[0].second = level;
		found = findBigger(remainer[0].first, set, level, -1);
		pos =  found - set.begin();
		set.insert(
					found,
					remainer.begin(),
					remainer.end());
		remainer.clear();
	}

	std::cout << "FOR PENDS LEVEL : " << pends_lvl << std::endl;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second == pends_lvl)
		{
			pends.push_back(i);
		}
	}

	std::cout << "pends level : " << pends_lvl << std::endl;
	std::cout << "pends size : " << pends.size() << std::endl;
	std::vector<int> order = jacob(pends.size());
	std::cout << "order size : " << order.size() << std::endl;

	for (size_t i = 0; i < order.size(); i++)
	std::cout << order[i] << " " << std::endl;

	for (size_t i = 0; i < pends.size(); i++)
	{
		int idx = pends[order[i]];

		for (int j = 0; j < pends_lvl; j++)
			temp.push_back(set[idx + j]);

		old_smaller.push_back(set[idx]);
		temp[0].second = level;

		for (int j = 0; j < pends_lvl; j++)
			set.erase(set.begin() + idx);

		found = findBigger(temp[0].first, set, level, set[idx - pends_lvl].first);
		// std::cout << temp[0].first << std::endl;
		// std::cout << " " << found[0].first << std::endl;
		set.insert(
				found,
				temp.begin(),
				temp.end());
			//if (i + j < set.size())
		pos =  found - set.begin();
		for (size_t k = i + 1; k < pends.size(); k++)
			if (pends[order[k]] >= pos)
				pends[order[k]] += pends_lvl;
		temp.clear();
	}


	set = setLevelBack(set, old_smaller, pends_lvl);


	return set;
}

size_t getMainSize(std::vector<std::pair<int, int> > &set, int level)
{
	size_t len = 0;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second >= level)
			len++;
	}
	return len;
}

void insertRemainer(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &remainer, int level)
{
	size_t i = set.size() - 1;
	for (; level > 0; level--)
	{
		remainer.insert(remainer.begin(), set[i--]);
		set.pop_back();
	}

	std::cout << "remainer: ";
	for (size_t i = 0; i < remainer.size(); i++)
	{
		std::cout << remainer[i].first << " - ";
	}
	std::cout << std::endl;
}

std::vector<std::pair<int, int> > vAlgo(std::vector<std::pair<int, int> > &set)
{

	std::vector<std::pair<int, int> >::iterator first_pair;
	std::vector<std::pair<int, int> >::iterator side_pair;

	std::vector<std::pair<int, int> > remainer;

	int level = find_current_level(set);

	if (getMainSize(set, level) % 2)
	{
		insertRemainer(set, remainer, level);
	}

	for (size_t i = 0; i < set.size(); i += level)
	{
		if (i + level < set.size())
		{
			std::vector<std::pair<int, int> >::iterator first_pair = set.begin() + i;
			side_pair = find_pair(set, set.begin() + i, level); //ça peut juste être set.begin() + i + level;
			if (side_pair == set.end())
				return set;

			if ((size_t)level >= (set.size() / 2))
			{
				if ((*first_pair).first > (*side_pair).first)
				{
					swapBlock(first_pair, side_pair);
				}
				return set = jsp(set, remainer, level);
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
	set = jsp(set, remainer, level);

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
	std::vector<std::pair<int, int> > remainer;
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
	std::cout << std::endl << std::endl;

	input = vAlgo(input);



	std::cout << std::endl << std::endl;
	std::cout << "result: " << std::endl;
	std::vector<int> v;

	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << "(" << input[i].first << ", " << input[i].second << ") - ";
		v.push_back(input[i].first);
	}
	std::cout << std::endl;




    if (std::is_sorted(v.begin(), v.end()))
        std::cout << "sorted\n";
    else
        std::cout << "not sorted\n";

	// std::vector<int> jaco = jacob(128);
	// for (size_t i = 0; i < jaco.size(); i++)
	// {
	// 	std::cout << jaco[i] << " ";
	// }

	std::cout << std::endl;

}




