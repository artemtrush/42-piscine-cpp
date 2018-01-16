#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
# include "Zombie.hpp"

class ZombieHorde {

private:
	Zombie	*horde;
	int		size;

public:
	ZombieHorde(int N);
	~ZombieHorde();
	void announce(void);
};

#endif