#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(int const nbr);
	Fixed(float const nbr);
	Fixed(const Fixed &fixed);

	Fixed& operator=(const Fixed& other);
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed& operator++();
	Fixed operator++(int);



	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(Fixed const &a, Fixed const &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(Fixed const &a, Fixed const &b);


	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
