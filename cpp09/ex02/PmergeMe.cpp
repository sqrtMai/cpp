#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	return *this;
}


std::deque<std::pair<int, int> >::iterator PmergeMe::find_pairDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> >::iterator it, int level)
{
	for (; it != set.end(); ++it)
	{
		for ( std::deque<std::pair<int, int> >::iterator next = it + 1; next != set.end(); ++next)
		{
			if ((*it).second == (*next).second && (*next).second == level)
			{
				return (next);
			}
		}
	}
	return set.end();
}

int PmergeMe::find_current_levelDQ(std::deque<std::pair<int, int> > &set)
{
	int level = -1;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second > level)
			level = set[i].second;
	}
	return level;
}

void PmergeMe::swapBlockDQ(std::deque<std::pair<int, int> >::iterator &first_pair, std::deque<std::pair<int, int> >::iterator &side_pair)
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

std::deque<std::pair<int, int> >::iterator PmergeMe::findBiggerDQ(int nb, std::deque<std::pair<int, int> > &set, int level, int winner)
{
	std::deque<size_t> mainIndex;

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

std::deque<std::pair<int, int> > PmergeMe::setLevelBackDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &old, int pends_lvl)
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

std::deque<int> PmergeMe::jacobDQ(size_t size)
{
	std::deque<long long> jacobstahl;
	std::deque<int> order;
	std::deque<int> current;

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

std::deque<std::pair<int, int> > PmergeMe::moveDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &remainer, int level)
{
	int pends_lvl = level / 2;

	std::deque<std::pair<int, int> > temp;
	std::deque<std::pair<int, int> > old_smaller;
	std::deque<std::pair<int, int> >::iterator found;
	std::deque<size_t> pends;

	size_t pos;


	if (remainer.size() >= 1)
	{
		old_smaller.push_back(remainer[0]);
		remainer[0].second = level;
		found = findBiggerDQ(remainer[0].first, set, level, -1);
		pos =  found - set.begin();
		set.insert(
					found,
					remainer.begin(),
					remainer.end());
		remainer.clear();
	}
	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second == pends_lvl)
			pends.push_back(i);
	}
	std::deque<int> order = jacobDQ(pends.size());

	for (size_t i = 0; i < pends.size(); i++)
	{
		int idx = pends[order[i]];

		for (int j = 0; j < pends_lvl; j++)
			temp.push_back(set[idx + j]);

		old_smaller.push_back(set[idx]);
		temp[0].second = level;
		for (int j = 0; j < pends_lvl; j++)
			set.erase(set.begin() + idx);

		for (size_t j = i + 1; j < pends.size(); j++)
		{
			if (pends[order[j]] > idx)
				pends[order[j]] -= pends_lvl;
		}

		found = findBiggerDQ(temp[0].first, set, level, set[idx - pends_lvl].first);
		set.insert(found, temp.begin(), temp.end());

		pos =  found - set.begin();
		for (size_t k = i + 1; k < pends.size(); k++)
			if (pends[order[k]] >= pos)
				pends[order[k]] += pends_lvl;
		temp.clear();
	}


	set = setLevelBackDQ(set, old_smaller, pends_lvl);


	return set;
}

size_t PmergeMe::getMainSizeDQ(std::deque<std::pair<int, int> > &set, int level)
{
	size_t len = 0;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second >= level)
			len++;
	}
	return len;
}

void PmergeMe::insertRemainerDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &remainer, int level)
{
	size_t i = set.size() - 1;
	for (; level > 0; level--)
	{
		remainer.insert(remainer.begin(), set[i--]);
		set.pop_back();
	}
}

std::deque<std::pair<int, int> > PmergeMe::vAlgoDQ(std::deque<std::pair<int, int> > &set)
{

	std::deque<std::pair<int, int> >::iterator first_pair;
	std::deque<std::pair<int, int> >::iterator side_pair;

	std::deque<std::pair<int, int> > remainer;

	int level = find_current_levelDQ(set);

	if (getMainSizeDQ(set, level) % 2)
	{
		insertRemainerDQ(set, remainer, level);
	}

	for (size_t i = 0; i < set.size(); i += level)
	{
		if (i + level < set.size())
		{
			std::deque<std::pair<int, int> >::iterator first_pair = set.begin() + i;
			side_pair = find_pairDQ(set, set.begin() + i, level); //ça peut juste être set.begin() + i + level;
			if (side_pair == set.end())
				return set;

			if ((size_t)level >= (set.size() / 2))
			{
				if ((*first_pair).first > (*side_pair).first)
				{
					swapBlockDQ(first_pair, side_pair);
				}
				return set = moveDQ(set, remainer, level);
			}
			if ((*first_pair).first < (*side_pair).first)
			{
				swapBlockDQ(first_pair, side_pair);
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

	set = vAlgoDQ(set);
	set = moveDQ(set, remainer, level);

	return set;
}

bool PmergeMe::hasDuplicate(std::vector<std::pair<int, int> > set)
{
	std::sort(set.begin(), set.end());

	for (size_t i = 1; i < set.size(); i++)
	{
		if (set[i] == set[i - 1])
			return true;
	}
	return false;
}

int PmergeMe::check_args(char **args)
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

std::vector<std::pair<int, int> >::iterator PmergeMe::find_pair(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> >::iterator it, int level)
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

int PmergeMe::find_current_level(std::vector<std::pair<int, int> > &set)
{
	int level = -1;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second > level)
			level = set[i].second;
	}
	return level;
}

void PmergeMe::swapBlock(std::vector<std::pair<int, int> >::iterator &first_pair, std::vector<std::pair<int, int> >::iterator &side_pair)
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

std::vector<std::pair<int, int> >::iterator PmergeMe::findBigger(int nb, std::vector<std::pair<int, int> > &set, int level, int winner)
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

std::vector<std::pair<int, int> > PmergeMe::setLevelBack(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &old, int pends_lvl)
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

std::vector<int> PmergeMe::jacob(size_t size)
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

std::vector<std::pair<int, int> > PmergeMe::move(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &remainer, int level)
{
	int pends_lvl = level / 2;

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
	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second == pends_lvl)
			pends.push_back(i);
	}
	std::vector<int> order = jacob(pends.size());

	for (size_t i = 0; i < pends.size(); i++)
	{
		int idx = pends[order[i]];

		for (int j = 0; j < pends_lvl; j++)
			temp.push_back(set[idx + j]);

		old_smaller.push_back(set[idx]);
		temp[0].second = level;
		for (int j = 0; j < pends_lvl; j++)
			set.erase(set.begin() + idx);

		for (size_t j = i + 1; j < pends.size(); j++)
		{
			if (pends[order[j]] > idx)
				pends[order[j]] -= pends_lvl;
		}

		found = findBigger(temp[0].first, set, level, set[idx - pends_lvl].first);
		set.insert(found, temp.begin(), temp.end());

		pos =  found - set.begin();
		for (size_t k = i + 1; k < pends.size(); k++)
			if (pends[order[k]] >= pos)
				pends[order[k]] += pends_lvl;
		temp.clear();
	}


	set = setLevelBack(set, old_smaller, pends_lvl);


	return set;
}

size_t PmergeMe::getMainSize(std::vector<std::pair<int, int> > &set, int level)
{
	size_t len = 0;

	for (size_t i = 0; i < set.size(); i++)
	{
		if (set[i].second >= level)
			len++;
	}
	return len;
}

void PmergeMe::insertRemainer(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &remainer, int level)
{
	size_t i = set.size() - 1;
	for (; level > 0; level--)
	{
		remainer.insert(remainer.begin(), set[i--]);
		set.pop_back();
	}
}

std::vector<std::pair<int, int> > PmergeMe::vAlgo(std::vector<std::pair<int, int> > &set)
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
				return set = move(set, remainer, level);
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

	set = vAlgo(set);
	set = move(set, remainer, level);

	return set;
}

double PmergeMe::getTimeUs()
	{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
	}


int PmergeMe::startDQ(char **argv)
{
	double timeB = getTimeUs();

	if (check_args(argv))
		return 1;

	std::vector<std::pair<int, int> > input;
	std::deque<std::pair<int, int> > inputDQ;

	for (size_t i = 1; argv[i]; i++)
	{
		std::pair<int, int> p;

		p.first = static_cast<int>(strtod(argv[i], NULL));
		p.second = 1;

		input.push_back(p);
		inputDQ.push_back(p);
	}

	if (hasDuplicate(input))
	{
		std::cerr << "Error: invalid arguments (duplicate)" << std::endl;
		return 1;
	}


	inputDQ = vAlgoDQ(inputDQ);


	double timeA = getTimeUs();

	std::cout << "Time to process a range of " << inputDQ.size() << " elements with std::deque : " << std::fixed << std::setprecision(9) <<  timeA - timeB << " s" << std::endl;

	return 0;
}

int PmergeMe::start(char **argv)
{
	double timeB = getTimeUs();

	if (check_args(argv))
		return 1;

	std::vector<std::pair<int, int> > input;
	std::deque<std::pair<int, int> > inputDQ;

	for (size_t i = 1; argv[i]; i++)
	{
		std::pair<int, int> p;

		p.first = static_cast<int>(strtod(argv[i], NULL));
		p.second = 1;

		input.push_back(p);
		inputDQ.push_back(p);
	}

	if (hasDuplicate(input))
	{
		std::cerr << "Error: invalid arguments (duplicate)" << std::endl;
		return 1;
	}
	std::cout << "Before: ";
	for (int i = 0; i < input.size(); i++)
		std::cout << input[i].first << " ";
	std::cout << std::endl;



	input = vAlgo(input);

	std::cout << "After: ";
	for (int i = 0; i < input.size(); i++)
		std::cout << input[i].first << " ";
	std::cout << std::endl << std::endl;


	double timeA = getTimeUs();

	std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << std::fixed << std::setprecision(9) <<  timeA - timeB << " s" << std::endl;

	timeB = getTimeUs();


	return startDQ(argv);
}
