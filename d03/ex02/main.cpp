#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::srand(time(NULL));

	ScavTrap	scav1("Mister-Robot");
	ScavTrap	scav2;
	std::cout << std::endl;
	scav1.rangedAttack("Scav Bot");
	scav2.takeDamage(20);
	std::cout << std::endl;
	scav1.meleeAttack("Scav Bot");
	scav2.takeDamage(30);
	std::cout << std::endl;
	scav2.takeDamage(100);
	scav2.takeDamage(100);
	std::cout << std::endl;
	scav2.beRepaired(100);
	scav2.beRepaired(100);
	std::cout << std::endl;
	scav2.challengeNewcomer();
	scav2.challengeNewcomer();
	scav2.challengeNewcomer();
	scav2.takeDamage(3);
	std::cout << "---------------------------------------------" << std::endl;

	FragTrap	frag1("Zhelezyaka");
	FragTrap	frag2;
	std::cout << std::endl;
	frag1.rangedAttack("Frag Bot");
	frag2.takeDamage(20);
	std::cout << std::endl;
	frag1.meleeAttack("Frag Bot");
	frag2.takeDamage(30);
	std::cout << std::endl;
	frag2.takeDamage(105);
	frag2.takeDamage(105);
	std::cout << std::endl;
	frag2.beRepaired(100);
	frag2.beRepaired(100);
	std::cout << std::endl;
	frag2.vaulthunter_dot_exe("Zhelezyaka");
	frag2.vaulthunter_dot_exe("Zhelezyaka");
	frag2.vaulthunter_dot_exe("Zhelezyaka");
	frag2.takeDamage(3);
	std::cout << std::endl;

	return 0;
}