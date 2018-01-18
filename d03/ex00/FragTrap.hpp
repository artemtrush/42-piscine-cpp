#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>

class FragTrap
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
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif