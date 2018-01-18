#include <iostream>
#include "Fixed.hpp"


int 	main( void )
{
	Fixed a(5);
	Fixed b(3);
	Fixed const c(Fixed(5));
	Fixed const d(Fixed(5.00001f));

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "A + B = " << (a + b) << std::endl;
	std::cout << "A - B = " << (a - b) << std::endl;
	std::cout << "A * B = " << (a * b) << std::endl;
	std::cout << "A / B = " << (a / b) << std::endl;

	if (a > b)
		std::cout << "A > B" << std::endl;
	if (a >= b)
		std::cout << "A >= B" << std::endl;
	if (b < a)
		std::cout << "B < A" << std::endl;
	if (b <= a)
		std::cout << "B <= A" << std::endl;
	if (b == a)
		std::cout << "B == A" << std::endl;
	if (b != a)
		std::cout << "B != A" << std::endl;
	if (a == a)
		std::cout << "A == A" << std::endl << std::endl;

	std::cout << "A    = " << a << std::endl;
	std::cout << "A++  = " << a++ << std::endl;
	std::cout << "A    = " << a << std::endl << std::endl;
	std::cout << "++A  = " << ++a << std::endl;
	std::cout << "A    = " << a << std::endl << std::endl;

	std::cout << "A    = " << a << std::endl;
	std::cout << "A--  = " << a-- << std::endl;
	std::cout << "A    = " << a << std::endl << std::endl;
	std::cout << "--A  = " << --a << std::endl;
	std::cout << "A    = " << a << std::endl << std::endl;


	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "D = " << d << std::endl;

	std::cout << "min a b = " << Fixed::min(a, b) << std::endl;
	std::cout << "max a b = " << Fixed::max(a, b) << std::endl;

	std::cout << "min c d = " << Fixed::min(c, d) << std::endl;
	std::cout << "max c d = " << Fixed::max(c, d) << std::endl;

	return (0);
}


// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }