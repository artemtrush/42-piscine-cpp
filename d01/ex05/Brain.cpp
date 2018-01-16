#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
	iq = 200;
}

Brain::~Brain() {}

std::string Brain::identify(void) const
{
	std::stringstream	stream;
	stream << this;
	return (stream.str());
}
