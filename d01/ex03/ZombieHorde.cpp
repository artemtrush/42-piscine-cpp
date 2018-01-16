#include "ZombieHorde.hpp"
#include <iostream>
#include <ctime>

ZombieHorde::ZombieHorde(int N) : size(N)
{
	int j;

	horde = new Zombie[size];
	for (int i = 0; i < size; i++)
	{
		horde[i].type = "vagabond";
		horde[i].name = "";
		j = (std::rand() % 4) + 4;
		while (j-- > 0)
		{
			horde[i].name += (std::rand() % 26) + 97;
		}
		horde[i].name[0] = std::toupper(horde[i].name[0]);
	}
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] horde;
	std::cout << "NOOOOOOO, my horde..." << std::endl;
}

void ZombieHorde::announce(void)
{
	for (int i = 0; i < size; i++)
	{
		horde[i].announce();
	}
}
