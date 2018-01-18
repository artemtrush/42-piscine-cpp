#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{

private:
	void 			child_initialization(void);

public:
	NinjaTrap(void);
	NinjaTrap(std::string const & name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	ninjaShoebox(FragTrap const & rhs);
	void	ninjaShoebox(ScavTrap const & rhs);
	void	ninjaShoebox(NinjaTrap const & rhs);
};

#endif