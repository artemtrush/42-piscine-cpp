#include "Warlock.hpp"

Warlock::~Warlock() 
{
	std::cout << _name << ": Ahhh, I see it clearly. This is the plane of SUCK..." << std::endl;
}

Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName(void) const
{
	return _name;
}

std::string const & Warlock::getTitle(void) const
{
	return _title;
}

void	Warlock::setTitle(std::string const & title)
{
	_title = title;
}

void 	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << " !" << std::endl;
}