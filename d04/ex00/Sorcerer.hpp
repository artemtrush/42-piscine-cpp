#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
private:
	std::string 	_name;
	std::string 	_title;
	Sorcerer();

public:
	~Sorcerer();
	Sorcerer(Sorcerer const & src);
	Sorcerer & operator=(Sorcerer const & rhs);

	Sorcerer(std::string name, std::string title);
	std::string	getName(void) const;
	std::string	getTitle(void) const;
	void 		polymorph(Victim const &) const;
};

std::ostream & operator<<(std::ostream & stream, Sorcerer const & rhs);

#endif
