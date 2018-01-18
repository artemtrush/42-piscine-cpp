#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::initialization(std::string const & name)
{
	this->_name 	= name;
	this->_hp 		= 100;
	this->_maxHp 	= 100;
	this->_lvl 		= 1;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(void) { this->initialization("Clap Bot"); }
ClapTrap::ClapTrap(std::string const & name) { this->initialization(name); }
ClapTrap::~ClapTrap(void) 
{
	std::cout  << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount = (amount <= this->_armor) ? 0 : amount - this->_armor;
	unsigned int previous = this->_hp;
	this->_hp = (amount >= this->_hp) ? 0 : this->_hp - amount; 
	std::cout << "[Battle]: " << this->_name << " damaged for " << 
		previous - this->_hp << " points (" << this->_hp << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int previous = this->_hp;
	this->_hp = this->_hp + amount;
	if (this->_hp > this->_maxHp)
		this->_hp = this->_maxHp;
	std::cout << "[Battle]: " << this->_name << " healed for " << 
		this->_hp - previous << " points (" << this->_hp << ")" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}