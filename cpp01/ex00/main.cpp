#include "Zombie.hpp"

int main(void)
{
	Zombie *test1 = newZombie("First (Heap)");
	test1->announce();
	delete test1;
	randomChump("Second (Stack)");
}
