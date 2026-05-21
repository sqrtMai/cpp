#include "ClapTrap.hpp"

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy && hit)
	{
		std::cout << "ClapTrap got repaired!" << std::endl;
		hit += amount;
		energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit)
	{
		hit -= amount;
		if (!hit)
			hit = 0;
	}
}

void ClapTrap::attack(const std::string &target)
{
	if (energy && hit)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->damage << " points of damage!" << std::endl;
		energy--;
	}
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap& other)
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

ClapTrap::ClapTrap() : hit(10), energy(10), damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hit(10), energy(10), damage(0)
{
	std::cout << "Constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
