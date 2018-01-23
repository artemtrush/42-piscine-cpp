#include "Enemy.hpp"

Enemy::Enemy() : Object() {}

Enemy::~Enemy() {}

Enemy::Enemy(Enemy const & src) : Object(src)
{
	*this = src;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_color = rhs._color;
		this->_size = rhs._size;
		this->_body = rhs._body;
		this->_hp = rhs._hp;
		this->_id = rhs._id;
		this->_width = rhs._width;
	}
	return *this;
}

int	Enemy::takeDamage()
{
	(this->_hp)--;
	if (this->_hp <= 0)
		return 1;
	return 0;
}

int	Enemy::getWidth()
{
	return this->_width;
}

Enemy::Enemy(int x, int y, int type) : Object(x, y, ENEMY_COLOR)
{
	switch (type)
	{
		case 1:
			firstType();
			this->_hp = 1;
			break;
		case 2:
			secondType();
			this->_hp = 3;
			break;
		case 3:
			thirdType();
			this->_hp = 30;
			break;
		default:
			fourthType();
			this->_hp = 1;
			break;
	}
	this->_id = 0;
}

void Enemy::firstType()
{
	int array[7 * 2] = {
		0,0, 2,0,
		1,1,
		0,2, 2,2,
		0,3, 2,3
	};
	this->_size = 7 * 2;
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
	this->_width = 3;
}

void Enemy::secondType()
{
	int array[10 * 2] = {
		1,0, 3,0,
		0,1, 4,1,
		1,2, 3,2,
		0,3, 4,3,
		0,4, 4,4
	};
	this->_size = 10 * 2;
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
	this->_width = 5;
}

void Enemy::thirdType()
{
	int array3[94 * 2] = {
		6,0, 7,0, 8,0, 9,0, 10,0, 11,0,
		4,1, 5,1, 12,1, 13,1,
		3,2, 14,2,
		3,3, 14,3,
		2,4, 15,4,
		2,5, 15,5,
		1,6, 4,6, 5,6, 6,6, 7,6, 10,6, 11,6, 12,6, 13,6, 16,6,
		1,7, 3,7, 4,7, 5,7, 6,7, 7,7, 10,7, 11,7, 12,7, 13,7, 14,7, 16,7,
		1,8, 3,8, 4,8, 5,8, 6,8, 7,8, 10,8, 11,8, 12,8, 13,8, 14,8, 16,8,
		1,9, 3,9, 4,9, 5,9, 6,9, 7,9, 10,9, 11,9, 12,9, 13,9, 14,9, 16,9,
		2,10, 4,10, 5,10, 6,10, 11,10, 12,10, 13,10, 15,10,
		3,11, 8,11, 9,11, 14,11,
		4,12, 8,12, 9,12, 13,12,
		4,13, 13,13,
		4,14, 7,14, 10,14, 13,14,
		5,15, 6,15, 7,15, 8,15, 9,15, 10,15, 11,15, 12,15
	};
	this->_size = 94 * 2;
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array3[i];
	this->_width = 18;
}

void Enemy::fourthType()
{
	int array[1 * 2] = {
		0, 0
	};
	this->_size = 1 * 2;
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
	this->_width = 1;
}
