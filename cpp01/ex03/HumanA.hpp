#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon& weapon;
	std::string name;
public:
	void attack();
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};

#endif
