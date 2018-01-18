#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP

#include <string>
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{

private:
	void 			super_initialization(void);

public:
	SuperTrap(void);
	SuperTrap(std::string const & name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap(void);
	SuperTrap & operator=(SuperTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
};

#endif