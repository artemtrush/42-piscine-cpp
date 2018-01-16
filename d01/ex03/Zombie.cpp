#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}
Zombie::~Zombie() {}

void	Zombie::announce(void)
{
	std::cout << "<" << name << "(" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}
