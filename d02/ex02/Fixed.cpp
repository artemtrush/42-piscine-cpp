#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	/*std::cout << "Default constructor called" << std::endl;*/
}

Fixed::Fixed(Fixed const & src)
{
	/*std::cout << "Copy constructor called" << std::endl;*/
	*this = src;
}

Fixed::Fixed(int const num)
{
	/*std::cout << "Int constructor called" << std::endl;*/
	this->_value = num << this->_fbits;
}

Fixed::Fixed(float const num)
{
	/*std::cout << "Float constructor called" << std::endl;*/
	this->_value = roundf(num * (1 << this->_fbits));
}

Fixed::~Fixed(void)
{
	/*std::cout << "Destructor called" << std::endl;*/
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	/*std::cout << "Assignation operator called" << std::endl;*/
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

/*-----------------------------------------------------------*/

Fixed 	Fixed::getResult(int const raw)
{
	Fixed	result;
	result.setRawBits(raw);
	return result;
}

bool		Fixed::operator>(Fixed const & rhs) const { return this->_value > rhs.getRawBits(); }
bool		Fixed::operator<(Fixed const & rhs) const { return this->_value < rhs.getRawBits(); }
bool		Fixed::operator>=(Fixed const & rhs) const { return this->_value >= rhs.getRawBits(); }
bool		Fixed::operator<=(Fixed const & rhs) const { return this->_value <= rhs.getRawBits(); }
bool		Fixed::operator==(Fixed const & rhs) const { return this->_value == rhs.getRawBits(); }
bool		Fixed::operator!=(Fixed const & rhs) const { return this->_value != rhs.getRawBits(); }

Fixed		Fixed::operator+(Fixed const & rhs) { return this->getResult(this->_value + rhs.getRawBits()); }
Fixed		Fixed::operator-(Fixed const & rhs) { return this->getResult(this->_value - rhs.getRawBits()); }
Fixed		Fixed::operator*(Fixed const & rhs) { return this->getResult((this->_value * rhs.getRawBits()) >> this->_fbits); }
Fixed		Fixed::operator/(Fixed const & rhs) { return this->getResult(this->_value / (rhs.getRawBits() >> this->_fbits)); }

Fixed		Fixed::operator--(int) { return this->getResult((this->_value)--); }
Fixed		Fixed::operator++(int) { return this->getResult((this->_value)++); }

Fixed &		Fixed::operator--(void)
{
	(this->_value)--;
	return *this;
}

Fixed &		Fixed::operator++(void)
{
	(this->_value)++;
	return *this;
}

Fixed &			Fixed::min(Fixed & lhs, Fixed & rhs) 			 { return (lhs <= rhs) ? lhs : rhs; }
Fixed &			Fixed::max(Fixed & lhs, Fixed & rhs) 			 { return (lhs >= rhs) ? lhs : rhs; }
const Fixed &	Fixed::min(Fixed const & lhs, Fixed const & rhs) { return (lhs <= rhs) ? lhs : rhs; }
const Fixed &	Fixed::max(Fixed const & lhs, Fixed const & rhs) { return (lhs >= rhs) ? lhs : rhs; }
