#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

int main(void)
{
	Zombie*		chump;
	ZombieEvent event;
	std::srand(unsigned(std::time(0)));

	event.setZombieType("vagabond");
	std::cout << "Random zombies:" << std::endl;
	event.randomChump();
	event.randomChump();
	event.randomChump();

	std::cout << "Planned zombies:" << std::endl;
	event.setZombieType("Altruist");
	chump = event.newZombie("atrush");
	chump->announce();
	delete chump;

	event.setZombieType("Lieutenant");
	chump = event.newZombie("vdoroshy");
	chump->announce();
	delete chump;

	return 0;
}