#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
}

FragTrap& FragTrap::operator =(const FragTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->hit = other.hit;
    this->energy = other.energy;
    this->damage = other.damage;
	this->name = other.name;
    return *this;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High five ???" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor" << std::endl;
}
