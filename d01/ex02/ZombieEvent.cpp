#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

ZombieEvent::ZombieEvent() 
{
	cztype = "unknown";
}

ZombieEvent::~ZombieEvent() {}

void	ZombieEvent::setZombieType(std::string type)
{
	cztype = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie* obj = new Zombie;
	obj->name = name;
	obj->type = cztype;
	return obj;
}

void	ZombieEvent::randomChump(void)
{
	Zombie		randomZombie;

	int i = (std::rand() % 4) + 4;
	randomZombie.name = "";
	while (i-- > 0)
	{
		randomZombie.name += (std::rand() % 26) + 97;
	}
	randomZombie.name[0] = std::toupper(randomZombie.name[0]);
	randomZombie.type = cztype;
	randomZombie.announce();
}
