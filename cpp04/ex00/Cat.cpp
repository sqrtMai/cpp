#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat copy constructor operator called" << std::endl;
}

Cat& Cat::operator =(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	this->type = other.type;
    return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "CAT IS MEOWING" << std::endl;
}
