#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	pointer = &str;
	std::string&	reference = str;

	std::cout << "string: " << str << std::endl;
	std::cout << "pointer: " << *pointer << std::endl;
	std::cout << "reference: " << reference << std::endl;
	return 0;
}