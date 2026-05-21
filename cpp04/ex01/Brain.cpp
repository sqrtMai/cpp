#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "Brain constructor is called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor operator called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}
