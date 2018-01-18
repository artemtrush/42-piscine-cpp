#include "NinjaTrap.hpp"
#include <iostream>

void NinjaTrap::child_initialization(void)
{
	this->_hp		= 60;
	this->_maxHp	= 60;
	this->_ep 		= 120;
	this->_maxEp 	= 120;
	this->_mdd 		= 60;
	this->_rdd 		= 5;
	this->_armor 	= 0;
	std::cout << "NinjaTrap constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(void) : ClapTrap("Ninja Bot")
{
	this->child_initialization();
}

NinjaTrap::NinjaTrap(std::string const & name) : ClapTrap(name)
{
	this->child_initialization();
}

NinjaTrap::~NinjaTrap(void) 
{
	std::cout << "NinjaTrap destructor called" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
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

void	NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << ": Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!" << std::endl;
	std::cout << "[Battle]: Ninja-TP " << this->_name << " attacks " << target <<
		" at range, causing " << this->_rdd << " points of damage." << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << ": Don't forget me!" << std::endl;
	std::cout << "[Battle]: Ninja-TP " << this->_name << " attacks " << target <<
		" at melee, causing " << this->_mdd << " points of damage." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & rhs)
{
	if (this->_ep >= 40)
    {
    	this->_ep -= 40;
        std::cout << this->_name << " gave to \"" << rhs.getName() << "\" opponent a Ragged shoe. So funny!" << std::endl;
    }
    else
    	std::cout << this->_name << ": Out of energy!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & rhs)
{
	if (this->_ep >= 40)
    {
    	this->_ep -= 40;
        std::cout << this->_name << " gave to \"" << rhs.getName() << "\" opponent a Dirty shoe. So dishonorably!" << std::endl;
    }
    else
    	std::cout << this->_name << ": Out of energy!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & rhs)
{
	if (this->_ep >= 40)
    {
    	this->_ep -= 40;
        std::cout << this->_name << " gave to \"" << rhs.getName() << "\" opponent a Wet shoe. So violently!" << std::endl;
    }
    else
    	std::cout << this->_name << ": Out of energy!" << std::endl;
}
