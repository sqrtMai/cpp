#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	std::string ideas[100];
public:
	Brain(/* args */);
	Brain(const Brain &other);
	Brain& operator =(const Brain &other);
	~Brain();
};


#endif
