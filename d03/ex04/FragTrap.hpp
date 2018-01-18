#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

private:
	void 			child_initialization(void);

public:
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif