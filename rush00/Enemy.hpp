#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "Object.hpp"

class Enemy : public Object
{
private:
	Enemy();
	void firstType();
	void secondType();
	void thirdType();
	void fourthType();
	int	_hp;
	int	_width;

public:
	Enemy(int x, int y, int type);
	~Enemy();
	Enemy(Enemy const & src);
	Enemy & operator=(Enemy const & rhs);

	int	takeDamage();
	int	getWidth();
};

#endif
