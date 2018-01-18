#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::initialization(std::string const & name)
{
	this->_name 	= name;
	this->_hp 		= 100;
	this->_maxHp 	= 100;
	this->_ep 		= 50;
	this->_maxEp 	= 50;
	this->_lvl 		= 1;
	this->_mdd 		= 20;
	this->_rdd 		= 15;
	this->_armor 	= 3;
	std::cout << this->_name << ": Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

ScavTrap::ScavTrap(void) { this->initialization("Scav Bot"); }
ScavTrap::ScavTrap(std::string const & name) { this->initialization(name); }
ScavTrap::~ScavTrap(void) 
{
	std::cout << this->_name << ": Robot down!" << std::endl;
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	amount = (amount <= this->_armor) ? 0 : amount - this->_armor;
	unsigned int previous = this->_hp;
	this->_hp = (amount >= this->_hp) ? 0 : this->_hp - amount; 
	std::cout << this->_name << ": Ow hohoho, that hurts! Yipes!" << std::endl;
	std::cout << "[Battle]: SCAV-TP " << this->_name << " damaged for " << 
		previous - this->_hp << " points (" << this->_hp << ")" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int previous = this->_hp;
	this->_hp = this->_hp + amount;
	if (this->_hp > this->_maxHp)
		this->_hp = this->_maxHp;
	std::cout << this->_name << ": Healsies!" << std::endl;
	std::cout << "[Battle]: SCAV-TP " << this->_name << " healed for " << 
		this->_hp - previous << " points (" << this->_hp << ")" << std::endl;
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
