#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP

#include <cstdint>

typedef struct Data
{
	int nbr;
}	Data;

class Serializer
{
private:
	Serializer(/* args */);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
