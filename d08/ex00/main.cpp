#include "easyfind.hpp"

int	main(void) {

	std::vector<int> mas;
	mas.push_back(1);
	mas.push_back(17);
	mas.push_back(42);

	try
	{
		easyfind(mas, 128);
	}
	catch (std::logic_error e)
	{
		std::cout << e.what() << std::endl;
	}

	*easyfind(mas, 42) = 128;
	std::cout << "Second attempt: " << *easyfind(mas, 128) << std::endl;

	return 0;
}