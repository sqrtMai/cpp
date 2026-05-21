#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor is called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor operator called" << std::endl;
	*this = other;
}

Dog& Dog::operator =(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	this->type = other.type;
    return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "DOG IS BARKING" << std::endl;
}
