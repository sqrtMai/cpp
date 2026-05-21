#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
private:
	std::string type;
public:
	WrongAnimal(/* args */);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator =(const WrongAnimal& other);
	~WrongAnimal();
	void makeSound() const;
};

#endif
