#include "FragTrap.hpp"
#include <iostream>

void FragTrap::initialization(std::string const & name)
{
	this->_name 	= name;
	this->_hp 		= 100;
	this->_maxHp 	= 100;
	this->_ep 		= 100;
	this->_maxEp 	= 100;
	this->_lvl 		= 1;
	this->_mdd 		= 30;
	this->_rdd 		= 20;
	this->_armor 	= 5;
	std::cout << this->_name << ": -- start bootup sequence..." << std::endl;
}

FragTrap::FragTrap(void) { this->initialization("Claptrap"); }
FragTrap::FragTrap(std::string const & name) { this->initialization(name); }
FragTrap::~FragTrap(void) 
{
	std::cout << this->_name << ": I'm too pretty to die!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << ": Present for you!" << std::endl;
	std::cout << "[Battle]: FR4G-TP " << this->_name << " attacks " << target <<
		" at range, causing " << this->_rdd << " points of damage." << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << ": Take that!" << std::endl;
	std::cout << "[Battle]: FR4G-TP " << this->_name << " attacks " << target <<
		" at melee, causing " << this->_mdd << " points of damage." << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == this->_maxHp)
		return;
	unsigned int previous = this->_hp;
	this->_hp = this->_hp + amount;
	if (this->_hp > this->_maxHp)
		this->_hp = this->_maxHp;
	std::cout << this->_name << ": Sweet life juice!" << std::endl;
	std::cout << "[Battle]: " << this->_name << "\'s health increased from " << 
		previous << " to " << this->_hp << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	(void)target;
}
