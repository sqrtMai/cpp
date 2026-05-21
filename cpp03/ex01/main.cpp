#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Mai");
	scav.attack("target");
	scav.takeDamage(254);
	return 0;
}
