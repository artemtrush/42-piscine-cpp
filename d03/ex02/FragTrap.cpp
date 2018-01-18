#include "FragTrap.hpp"
#include <iostream>

void FragTrap::child_initialization(void)
{
	this->_ep 		= 100;
	this->_maxEp 	= 100;
	this->_mdd 		= 30;
	this->_rdd 		= 20;
	this->_armor 	= 5;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap("Frag Bot")
{
	this->child_initialization();
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	this->child_initialization();
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap destructor called" << std::endl;
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string pool[] = {
		"Hyperiooooon Punch!",
		"Sting like a butterfly!",
		"Frost exhaust!",
		"Scram!",
		"Exploooooosions!"
	};
    if (this->_ep >= 25)
    {
    	this->_ep -= 25;
        std::cout << this->_name << ": " << pool[std::rand() % 5] << std::endl;
        std::cout << "[Battle]: FR4G-TP " << this->_name << " use special attack on " << target << std::endl;
    }
    else
    	std::cout << this->_name << ": Out of energy!" << std::endl;
}
