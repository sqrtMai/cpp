#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator=(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();
};

#endif
