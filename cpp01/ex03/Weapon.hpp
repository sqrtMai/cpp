#ifndef WEAPON
#define WEAPON

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	const std::string &getType();
	void setType(std::string type);
	Weapon();
	Weapon(std::string type);
	~Weapon();
};

#endif
