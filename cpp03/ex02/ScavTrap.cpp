#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator =(const ScavTrap &other)
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

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Scavtrap destructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}
