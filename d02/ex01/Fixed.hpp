#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int					_value;
	static const int	_fbits = 8;

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
};

std::ostream &	operator<<(std::ostream & stream, Fixed const & rhs);

#endif