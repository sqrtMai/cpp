#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	//const Animal c;
	const Animal *a = new Dog();
	const Animal *b = new Cat();

	delete a;
	delete b;
}
