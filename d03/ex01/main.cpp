#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::srand(time(NULL));
	ScavTrap	r1("Mister-Robot");
	ScavTrap	r2;

	std::cout << std::endl;

	r1.rangedAttack("Scav Bot");
	r2.takeDamage(20);

	std::cout << std::endl;

	r1.meleeAttack("Scav Bot");
	r2.takeDamage(30);

	std::cout << std::endl;
	
	r2.takeDamage(100);
	r2.takeDamage(100);

	std::cout << std::endl;

	r2.beRepaired(100);
	r2.beRepaired(100);

	std::cout << std::endl;

	r2.challengeNewcomer();
	r2.challengeNewcomer();
	r2.challengeNewcomer();
	r2.challengeNewcomer();
	r2.challengeNewcomer();
	r2.takeDamage(3);

	std::cout << std::endl;

	return 0;
}