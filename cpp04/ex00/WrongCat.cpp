#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */) : WrongAnimal()
{
	std::cout << "Animal constructor is called" << std::endl;
	this->type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	std::cout << "Wrong Cat copy constructor operator called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator =(const WrongCat &other)
{
	std::cout << "Wrong Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	this->type = other.type;
    return *this;
}


WrongCat::~WrongCat()
{
	std::cout << "Animal destructor is called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Cat is MEOWING" << std::endl;
}
