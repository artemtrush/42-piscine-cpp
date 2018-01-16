#include "Weapon.hpp"

Weapon::Weapon(std::string p1) : type(p1) {}
Weapon::~Weapon() {}

void				Weapon::setType(std::string value)
{
	type = value;
}

std::string const &	Weapon::getType(void)
{
	return type;
}

