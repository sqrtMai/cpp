#include "HumanA.hpp"
#include "HumanB.hpp"
int main(void)
{
	Weapon club = Weapon("club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some type shi");
	bob.attack();

	Weapon sword = Weapon("Sword");
	HumanB jack("jack");
	jack.setWeapon(sword);
	jack.attack();
	sword.setType("Zweihander");
	jack.attack();

}
