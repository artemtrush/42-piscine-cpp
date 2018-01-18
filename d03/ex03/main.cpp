#include <iostream>
#include "NinjaTrap.hpp"

int main(void)
{
	std::srand(time(NULL));

	NinjaTrap	Ninja1("Rogue");
	NinjaTrap	Ninja2;
	std::cout << std::endl;
	Ninja1.rangedAttack("Ninja Bot");
	Ninja2.takeDamage(20);
	std::cout << std::endl;
	Ninja1.meleeAttack("Ninja Bot");
	Ninja2.takeDamage(30);
	std::cout << std::endl;
	Ninja2.takeDamage(100);
	Ninja2.takeDamage(100);
	std::cout << std::endl;
	Ninja2.beRepaired(100);
	Ninja2.beRepaired(100);
	std::cout << std::endl;

	NinjaTrap original("ODIN");
	original.takeDamage(3);
	NinjaTrap copy(original);
	copy.beRepaired(1);

	copy.ninjaShoebox(FragTrap("Frag man"));
	copy.ninjaShoebox(ScavTrap("Scav man"));
	copy.ninjaShoebox(NinjaTrap("Ninja man"));
	return 0;
}