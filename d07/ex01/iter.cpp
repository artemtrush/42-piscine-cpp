#include <iostream>

template < typename T >
void iter(T * arr, size_t size, void (*call)(T &))
{
	for (size_t i = 0; i < size; i++)
		call(arr[i]);
}

template < typename T >
void out(T & var) {
	std::cout << var << std::endl;
}

int main(void)
{
	int		ints[5] = {0, 13, 42, 228, 2018};
	char	chars[7] = "atrush";
	float	floats[3] = {3.14, 8.3, 15.2};

	std::cout << std::endl << "integer array" << std::endl;
	::iter(ints, 5, out);
	std::cout << std::endl << "char array" << std::endl;
	iter(chars, 6, out);
	std::cout << std::endl << "float array" << std::endl;
	iter(floats, 3, out);
	return 0;
}
