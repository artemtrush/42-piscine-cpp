#include "Player.hpp"

Player::Player() : Object() {}

Player::~Player() {}

Player::Player(Player const & src) : Object(src) {}

Player & Player::operator=(Player const & rhs)
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

Player::Player(int x, int y) : Object(x, y, PLAYER_COLOR) {
	this->_size = 26 * 2;
	int array[26 * 2] = {
		3, 0,
		2, 1,
		3, 1,
		4, 1,
		2, 2,
		3, 2,
		4, 2,
		3, 3,
		1, 4,
		2, 4,
		3, 4,
		4, 4,
		5, 4,
		0, 5,
		1, 5,
		2, 5,
		3, 5,
		4, 5,
		5, 5,
		6, 5,
		0, 6,
		1, 6,
		2, 6,
		4, 6,
		5, 6,
		6, 6
	};
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
}