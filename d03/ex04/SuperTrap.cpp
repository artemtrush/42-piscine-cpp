#include "SuperTrap.hpp"
#include <iostream>

void SuperTrap::super_initialization(void)
{
	this->_hp		= 100;
	this->_maxHp	= 100;
	this->_ep 		= 120;
	this->_maxEp 	= 120;
	this->_mdd 		= 60;
	this->_rdd 		= 20;
	this->_armor 	= 5;
	std::cout << "SuperTrap constructor called" << std::endl;
}

SuperTrap::SuperTrap(void) : FragTrap("SuperBot"), NinjaTrap("SuperBot")
{
	this->super_initialization();
}

SuperTrap::SuperTrap(std::string const & name) : FragTrap(name), NinjaTrap(name)
{
	this->super_initialization();
}

SuperTrap::~SuperTrap(void) 
{
	std::cout << "SuperTrap destructor called" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	*this = src;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name		= rhs._name;
		this->_hp 		= rhs._hp;
		this->_maxHp	= rhs._maxHp;
		this->_ep 		= rhs._ep;
		this->_maxEp 	= rhs._maxEp;
		this->_lvl 		= rhs._lvl;
		this->_mdd 		= rhs._mdd;
		this->_rdd 		= rhs._rdd;
		this->_armor	= rhs._armor;
	}
	return *this;
}

void	SuperTrap::rangedAttack(std::string const & target) { FragTrap::rangedAttack(target); };
void	SuperTrap::meleeAttack(std::string const & target) { NinjaTrap::meleeAttack(target); };
