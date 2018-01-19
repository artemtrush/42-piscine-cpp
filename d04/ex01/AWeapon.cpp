#include "AWeapon.hpp"

AWeapon::AWeapon(){}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(name), _apcost(apcost), _damage(damage) {}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return *this;
}

AWeapon::~AWeapon(){}

std::string const & AWeapon::getName() const
{
	return this->_name;
}

int AWeapon::getAPCost() const
{
	return this->_apcost;
}

int AWeapon::getDamage() const
{
	return this->_damage;
}