#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP
# include "Zombie.hpp"
# include <string>

class ZombieEvent {

private:
	std::string	cztype;

public:
	ZombieEvent();
	~ZombieEvent();
	void 	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	void	randomChump(void);
};

#endif