#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
public:

	int start(char **argv);

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
private:
	std::deque<std::pair<int, int> >::iterator find_pairDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> >::iterator it, int level);
	int find_current_levelDQ(std::deque<std::pair<int, int> > &set);
	void swapBlockDQ(std::deque<std::pair<int, int> >::iterator &first_pair, std::deque<std::pair<int, int> >::iterator &side_pair);
	std::deque<std::pair<int, int> >::iterator findBiggerDQ(int nb, std::deque<std::pair<int, int> > &set, int level, int winner);
	std::deque<std::pair<int, int> > setLevelBackDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &old, int pends_lvl);
	std::deque<int> jacobDQ(size_t size);
	std::deque<std::pair<int, int> > moveDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &reminer, int level);
	size_t getMainSizeDQ(std::deque<std::pair<int, int> > &set, int level);
	void insertRemainerDQ(std::deque<std::pair<int, int> > &set, std::deque<std::pair<int, int> > &reminer, int level);
	std::deque<std::pair<int, int> > vAlgoDQ(std::deque<std::pair<int, int> > &set);
	std::vector<std::pair<int, int> >::iterator find_pair(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> >::iterator it, int level);
	int find_current_level(std::vector<std::pair<int, int> > &set);
	void swapBlock(std::vector<std::pair<int, int> >::iterator &first_pair, std::vector<std::pair<int, int> >::iterator &side_pair);
	std::vector<std::pair<int, int> >::iterator findBigger(int nb, std::vector<std::pair<int, int> > &set, int level, int winner);
	std::vector<std::pair<int, int> > setLevelBack(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &old, int pends_lvl);
	std::vector<int> jacob(size_t size);
	std::vector<std::pair<int, int> > move(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &reminer, int level);
	size_t getMainSize(std::vector<std::pair<int, int> > &set, int level);
	std::vector<std::pair<int, int> > vAlgo(std::vector<std::pair<int, int> > &set);
	void insertRemainer(std::vector<std::pair<int, int> > &set, std::vector<std::pair<int, int> > &reminer, int level);
	int check_args(char **args);
	double getTimeUs();
	bool hasDuplicate(std::vector<std::pair<int, int> > set);
	int startDQ(char **argv);
};

#endif
