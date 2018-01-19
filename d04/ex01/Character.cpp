#include "Character.hpp"

Character::Character(){}

Character::Character(std::string const & name) :
	_name(name), _ap(40), _weapon(NULL) {}

Character::Character(Character const & src)
{
	*this = src;
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_ap = rhs._ap;
		this->_weapon = rhs._weapon;
	}
	return *this;
}

Character::~Character(){}

void Character::recoverAP()
{
	this->_ap = (this->_ap + 10 > 40) ? 40 : this->_ap + 10;
}

void Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
	if (!(this->_weapon))
		return;
	if (this->_weapon->getAPCost() > this->_ap)
		return;
	this->_ap -= this->_weapon->getAPCost();
	std::cout << this->_name << " attacks " << enemy->getType() << 
		" with a " << this->_weapon->getName() << std::endl;
	enemy->takeDamage(this->_weapon->getDamage());
	this->_weapon->attack();
	if (enemy->getHP() == 0)
		delete enemy;
}

std::string const & Character::getName() const
{
	return this->_name;
}

int					Character::getAP() const
{
	return this->_ap;
}

AWeapon *			Character::getWeapon() const
{
	return this->_weapon;
}

std::ostream & 	operator<<(std::ostream & stream, Character const & rhs)
{
	if (rhs.getWeapon())
	{
		stream << rhs.getName() << " has " << rhs.getAP() <<
			" AP and wields a " << (rhs.getWeapon())->getName() << std::endl;
	}
	else
	{
		stream << rhs.getName() << " has " << rhs.getAP() <<
		" AP and is unarmed" << std::endl;
	}
	return stream;
}