#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int					_value;
	static const int	_fbits = 8;
	Fixed 				getResult(int const num);

public:

	Fixed(void);
	Fixed(int const num);
	Fixed(float const num);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &			operator=(Fixed const & rhs);
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;

	bool			operator>(Fixed const & rhs) const;
	bool			operator<(Fixed const & rhs) const;
	bool			operator>=(Fixed const & rhs) const;
	bool			operator<=(Fixed const & rhs) const;
	bool			operator==(Fixed const & rhs) const;
	bool			operator!=(Fixed const & rhs) const;

	Fixed			operator+(Fixed const & rhs);
	Fixed			operator-(Fixed const & rhs);
	Fixed			operator*(Fixed const & rhs);
	Fixed			operator/(Fixed const & rhs);

	Fixed &			operator--(void); // prefix --
	Fixed &			operator++(void); // prefix ++
	Fixed			operator--(int); // prefix --
	Fixed			operator++(int); // prefix ++

	static Fixed &			min(Fixed & lhs, Fixed & rhs);
	static Fixed &			max(Fixed & lhs, Fixed & rhs);
	static const Fixed &	min(Fixed const & lhs, Fixed const & rhs);
	static const Fixed &	max(Fixed const & lhs, Fixed const & rhs);
};

std::ostream &	operator<<(std::ostream & stream, Fixed const & rhs);

#endif