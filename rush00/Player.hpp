#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Object.hpp"

class Player : public Object
{
private:
	Player();

public:
	Player(int x, int y);
	~Player();
	Player(Player const & src);
	Player & operator=(Player const & rhs);
};

#endif
