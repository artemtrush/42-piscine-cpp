#include "ZombieHorde.hpp"
#include <iostream>
#include <ctime>

int main(void)
{
	std::srand(unsigned(std::time(0)));

	ZombieHorde	for_the_horde(std::rand() % 30 + 1);
	for_the_horde.announce();
	return 0;
}