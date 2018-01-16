#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {

private:
	std::string	type;

public:
	Weapon(std::string p1);
	~Weapon();
	void				setType(std::string value);
	std::string const &	getType(void);
};

#endif