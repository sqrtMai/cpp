#include "Animal.hpp"

Animal& Animal::operator =(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::Animal(/* args */)
{
	std::cout << "Animal constructor is called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}
