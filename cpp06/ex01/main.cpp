#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data nbr;

	nbr.nbr = 42;
	std::cout << "Data address = " << &nbr << std::endl;

	uintptr_t serial =  Serializer::serialize(&nbr);

	std::cout << "Serialize result = " << serial << std::endl;

	Data *data = Serializer::deserialize(serial);

	std::cout << "Data nbr = " << data->nbr << std::endl;
	std::cout << "Data address = " << data << std::endl;



}
