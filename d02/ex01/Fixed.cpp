#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

int			Fixed::getRawBits(void) const
{
	/*std::cout << "getRawBits member function called" << std::endl;*/
	return this->_value;
}

void		Fixed::setRawBits(int const raw)
{
	/*std::cout << "setRawBits member function called" << std::endl;*/
	this->_value = raw;
}

/*-----------------------------------------------------------*/

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << this->_fbits;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fbits));
}

float	Fixed::toFloat(void) const
{
	return	float(this->_value) / (1 << this->_fbits);
}

int		Fixed::toInt(void) const
{
	return	roundf(this->_value >> this->_fbits);
}

std::ostream &	operator<<(std::ostream & stream, Fixed const & rhs)
{
	stream << rhs.toFloat();
	return stream;
}
