#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator =(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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
ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Scavtrap constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
	if (energy)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
		energy--;
	}
}
