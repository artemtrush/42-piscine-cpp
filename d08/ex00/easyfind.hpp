#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

template< typename T >
typename T::iterator easyfind(T & container, int needle)
{
	/*If no elements match, the function returns last.*/
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
	{
		std::stringstream exc;
		exc << "Value \'" << needle << "\'' not found in container.";
		throw std::logic_error(exc.str());
	}
	return it;
}

#endif
