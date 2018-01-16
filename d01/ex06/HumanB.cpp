#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string p1) : name(p1) {}

HumanB::~HumanB() {}

void 	HumanB::attack(void)
{
	std::cout << name << " attacks with his " << gun->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon & val)
{
	gun = &val;
}
