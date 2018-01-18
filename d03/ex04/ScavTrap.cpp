#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::child_initialization(void)
{
	this->_ep 		= 50;
	this->_maxEp 	= 50;
	this->_mdd 		= 20;
	this->_rdd 		= 15;
	this->_armor 	= 3;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap("Scav Bot")
{
	this->child_initialization();
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	this->child_initialization();
}

ScavTrap::~ScavTrap(void) 
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << ": Pull pin, throw!" << std::endl;
	std::cout << "[Battle]: SCAV-TP " << this->_name << " attacks " << target <<
		" at range, causing " << this->_rdd << " points of damage." << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << ": Bad guy go die!" << std::endl;
	std::cout << "[Battle]: SCAV-TP " << this->_name << " attacks " << target <<
		" at melee, causing " << this->_mdd << " points of damage." << std::endl;
}

void	ScavTrap::challengeNewcomer(void)
{
	std::string pool[] = {
		"Gallon Milk Challenge!",
		"Pickle Challenge!",
		"Ice Bucket Challenge!",
		"Say Anything Challenge!",
		"Here Comes Cinnamon Challenge!"
	};
    std::cout << this->_name << ": " << pool[std::rand() % 5] << std::endl; 
}
