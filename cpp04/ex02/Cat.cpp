#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor operator called" << std::endl;
	this->brain = new Brain(*other.brain);
	this->type = other.type;
}

Cat& Cat::operator =(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	delete this->brain;
    this->brain = new Brain(*other.brain);
    return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "CAT IS MEOWING" << std::endl;
}
