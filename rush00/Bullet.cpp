#include "Bullet.hpp"

Bullet::Bullet() : Object() {}

Bullet::~Bullet() {}

Bullet::Bullet(Bullet const & src) : Object(src) {}

Bullet & Bullet::operator=(Bullet const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_color = rhs._color;
		this->_size = rhs._size;
		this->_body = rhs._body;
		this->_id = rhs._id;
	}
	return *this;
}

Bullet::Bullet(int x, int y) : Object(x, y, BULLET_COLOR) {
	this->_size = 2;
	int array[2] = {
		0, 0
	};
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
}