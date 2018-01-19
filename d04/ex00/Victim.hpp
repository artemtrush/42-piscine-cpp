#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{

protected:
	std::string 	_name;
	Victim();

public:
	virtual ~Victim();
	Victim(Victim const & src);
	Victim & operator=(Victim const & rhs);

	Victim(std::string name);
	std::string	getName(void) const;
	virtual void getPolymorphed() const;

};

std::ostream & operator<<(std::ostream & stream, Victim const & rhs);

#endif
