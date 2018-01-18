#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

private:
	void 			child_initialization(void);

public:
	ScavTrap(void);
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	challengeNewcomer(void);
};

#endif