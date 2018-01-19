#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp), _type(type) {}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_type = rhs._type;
	}
	return *this;
}

Enemy::~Enemy(){}

std::string const & Enemy::getType() const
{
	return this->_type;
}

int Enemy::getHP() const
{
	return this->_hp;
}

void Enemy::takeDamage(int value)
{
	if (value < 0)
		return;
	_hp = (value >= _hp) ? 0 : _hp - value;
}