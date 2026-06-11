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


size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


std::vector<std::pair<int,int> > insertionPhase(std::vector<std::pair<int,int> >& set)
{
    int level = find_current_level(set);

    std::vector<int> main_chain;
    std::vector<std::pair<int,int> > pend;

    // b1 = loser du premier winner, inséré gratuitement
    main_chain.push_back(set[level / 2].first);

    // Tous les winners (second == level) → main_chain
    // Leur loser direct (second == level/2) → pend avec leur borne
    for (size_t i = 0; i < set.size(); i += level)
    {
        main_chain.push_back(set[i].first);
        if (i > 0)  // b1 déjà ajouté
            pend.push_back(std::make_pair(set[i + level/2].first, set[i].first));
    }

    // Les sous-losers (second < level/2) → aussi dans pend
    // On les cherche par leur second
    for (size_t i = 0; i < set.size(); i++)
    {
        if (set[i].second < level / 2 && set[i].second >= 1)
        {
            // Trouver le winner qui le couvre
            // C'est le premier élément de second==level dans son bloc
            size_t block = (i / level) * level;
            int bound = set[block].first;
            pend.push_back(std::make_pair(set[i].first, bound));
        }
    }

    size_t jk = 2;

    while (!pend.empty())
    {
        size_t j_prev = jacobsthal(jk - 1);
        size_t j_curr = jacobsthal(jk);
        size_t group_size = j_curr - j_prev;
        if (group_size > pend.size())
            group_size = pend.size();

        for (size_t i = group_size; i > 0; i--)
        {
            int val      = pend[i - 1].first;
            int bound_val = pend[i - 1].second;

            std::vector<int>::iterator bound_it = std::find(main_chain.begin(), main_chain.end(), bound_val);
            ++bound_it;

            std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), bound_it, val);
            main_chain.insert(pos, val);
        }

        pend.erase(pend.begin(), pend.begin() + group_size);
        jk++;
    }

    std::vector<std::pair<int,int> > result;
    for (size_t i = 0; i < main_chain.size(); i++)
        result.push_back(std::make_pair(main_chain[i], 1));

    return result;
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
	input = insertionPhase(input);
	for (size_t i = 0; i < input.size(); i++)
	{
		std::cout << "(" << input[i].first <<  ") - ";
	}
	std::cout << std::endl;

}




