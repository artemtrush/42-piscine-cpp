#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>

class ScavTrap
{

private:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_maxHp;
	unsigned int	_ep;
	unsigned int	_maxEp;
	unsigned int	_lvl;
	unsigned int	_mdd;
	unsigned int	_rdd;
	unsigned int	_armor;
	void 			initialization(std::string const & name);

public:
	ScavTrap(void);
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(void);
};

#endif