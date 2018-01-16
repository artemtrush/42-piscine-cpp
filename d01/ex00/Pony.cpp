#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony(std::string str) : name(str)
{
	std::cout << name << " came to the UNIT." << std::endl;
}

Pony::~Pony()
{
	std::cout << "Somewhere in the world one pony has died. Perhaps her name was " << name << "." << std::endl;
}
