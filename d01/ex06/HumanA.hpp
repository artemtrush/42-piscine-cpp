#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <string>
# include "Weapon.hpp"

class HumanA {

private:
	std::string	name;
	Weapon&		gun;

public:
	HumanA(std::string p1, Weapon & p2);
	~HumanA();
	void 		attack(void);

};

#endif