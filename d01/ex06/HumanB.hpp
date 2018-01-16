#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <string>
# include "Weapon.hpp"

class HumanB {

private:
	std::string	name;
	Weapon*		gun;

public:
	HumanB(std::string p1);
	~HumanB();
	void 		attack(void);
	void		setWeapon(Weapon & val);
};

#endif