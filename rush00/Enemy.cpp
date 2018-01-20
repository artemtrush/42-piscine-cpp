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
			this->_hp = 5;
			break;
		case 2:
			secondType();
			this->_hp = 5;
			break;
		case 3:
			thirdType();
			this->_hp = 20;
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
	int array[1 * 2] = {
		0, 0
	};
	this->_size = 1 * 2;
	this->_body = new int [this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_body[i] = array[i];
	this->_width = 1;
}

void Enemy::secondType()
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

void Enemy::thirdType()
{
	int array3[28 * 2] = {
		6,0, 7,0, 8,0, 9,0, 10,0, 11,0,
		4,1, 5,1, 12,1, 13,1,
		3,2, 14,2,
		3,3, 14,3,
		2,4, 15,4,
		2,5, 15,5,
		1,6, 4,6, 5,6, 6,6, 7,6, 10,6, 11,6, 12,6, 13,6, 16,6
	};
	this->_size = 28 * 2;
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
