#include "iter.hpp"
#include <iostream>

void add_one(int *nb)
{
	(*nb)++;
}

void print_nb_value(const int *nb)
{
	std::cout << *nb << std::endl;
}

int main(void)
{
	int *array = new int[5];
	for (int i = 0; i < 5; i++)
		array[i] = i;
	const int array_const[5] = {0, 1, 2, 3, 4};

	std::cout << "array before: " << std::endl;

	::iter(array, 5, print_nb_value); // Itère parmis toutes les values et les print une à une

	std::cout << std::endl << "array after : " << std::endl;

	::iter(array, 5, add_one); // Incrémente de 1 chaque value
	::iter(array, 5, print_nb_value);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Const example: " << std::endl;

	::iter(array_const, 5, print_nb_value); // Itère parmis toutes les values et les print une à une

	delete []array;
}
