#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{

private:
	void 			initialization(std::string const & name);

protected:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_maxHp;
	unsigned int	_ep;
	unsigned int	_maxEp;
	unsigned int	_lvl;
	unsigned int	_mdd;
	unsigned int	_rdd;
	unsigned int	_armor;

public:
	ClapTrap(void);
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & rhs);
	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif