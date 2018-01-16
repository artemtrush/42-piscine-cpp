#include "Human.hpp"

Human::Human() {}
Human::~Human() {}

std::string		Human::identify(void)
{
	return marrow.identify();
}

Brain const	&	Human::getBrain(void)
{
	return marrow;
}
