#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor is called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
	this->type = other.type;
}

Dog& Dog::operator =(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	delete this->brain;
	this->brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "DOG IS BARKING" << std::endl;
}
