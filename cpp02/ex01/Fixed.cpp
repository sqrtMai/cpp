#include "Fixed.hpp"


Fixed::Fixed(int const nbr)
{
	this->value = nbr << this->bits;
}
Fixed::Fixed(float const nbr)
{
	this->value = roundf(nbr * (1 << this->bits)); // nbr << marche que sur les int, pour float tu dois multiplier et donc transfo
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;

    this->value = other.value;
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

float Fixed::toFloat() const
{
	return (float)this->value / (1 << this->bits);
}

int Fixed::toInt() const
{
	return this->value >> this->bits;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
