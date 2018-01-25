#include <iostream>
#include "Array.tpp"

int	main(void) {

	Array<float> a(20);
	for (size_t i = 0; i < a.size(); ++i)
		a[i] = 4.2 + i;
	Array<float> b(a);
	Array<float> c(100);
	c = a;

	std::cout << "A:" << std::endl;
	for (size_t i = 0; i < a.size(); ++i)
		std::cout << a[i] << "  ";
	std::cout << std::endl << "B:" << std::endl;
	for (size_t i = 0; i < b.size(); ++i)
		std::cout << b[i] << "  ";
	std::cout << std::endl << "C:" << std::endl;
	for (size_t i = 0; i < c.size(); ++i)
		std::cout << c[i] << "  ";
	std::cout << std::endl;


	Array<std::string> str(3);
	str[0] = "lol";
	str[1] = "kek";
	str[2] = "42sc";
	std::cout << "String" << std::endl;
	for (size_t i = 0; i < str.size(); ++i)
		std::cout << str[i] << std::endl;

	return 0;
}
