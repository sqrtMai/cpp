#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	void setWeapon(Weapon &weapon);
	void attack();
	HumanB(std::string name);
	~HumanB();
};



#endif
