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

	std::cout << "array before: ";
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl << "array after : ";
	::iter(array, 5, add_one);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	::iter(array, 5, print_nb_value);
	delete []array;
}
