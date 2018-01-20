#ifndef BULLET_HPP
#define BULLET_HPP

#include <iostream>
#include "Object.hpp"

class Bullet : public Object
{
private:
	Bullet();

public:
	Bullet(int x, int y);
	~Bullet();
	Bullet(Bullet const & src);
	Bullet & operator=(Bullet const & rhs);
};

#endif
