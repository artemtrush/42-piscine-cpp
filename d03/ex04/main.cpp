#include <iostream>
#include "SuperTrap.hpp"

int main(void)
{
	std::srand(time(NULL));

	SuperTrap	Super1("Rogue");
	SuperTrap	Super2;
	std::cout << std::endl;
	Super1.rangedAttack("Super Bot");
	Super2.takeDamage(20);
	std::cout << std::endl;
	Super1.meleeAttack("Super Bot");
	Super2.takeDamage(30);
	std::cout << std::endl;
	Super2.takeDamage(100);
	Super2.takeDamage(100);
	std::cout << std::endl;
	Super2.beRepaired(100);
	Super2.beRepaired(100);
	std::cout << std::endl;

	SuperTrap original("ODIN");
	original.takeDamage(3);
	SuperTrap copy(original);
	copy.beRepaired(1);

	copy.ninjaShoebox(FragTrap("Frag man"));
	copy.ninjaShoebox(ScavTrap("Scav man"));
	copy.vaulthunter_dot_exe("Ninja man");
	return 0;
}