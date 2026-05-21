#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	std::cout << "Wrong Animal constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "Wrong Animal copy constructor operator called" << std::endl;
}

WrongAnimal &WrongAnimal::operator =(const WrongAnimal &other)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	this->type = other.type;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor is called" << std::endl;
}
void WrongAnimal::makeSound() const
{
	std::cout << "Cat is barking" << std::endl;
}
