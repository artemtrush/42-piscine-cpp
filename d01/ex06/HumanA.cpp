#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string p1, Weapon & p2) : name(p1), gun(p2) {}

HumanA::~HumanA() {}

void 	HumanA::attack(void)
{
	std::cout << name << " attacks with his " << gun.getType() << std::endl;
}


