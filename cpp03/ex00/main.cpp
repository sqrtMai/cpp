#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Mai");

	for (int i = 0; i < 9; i++)
		clap.attack("HHH");
	clap.beRepaired(10);
	clap.beRepaired(10);
	clap.beRepaired(10);
	clap.takeDamage(1000000);

	return 0;
}
