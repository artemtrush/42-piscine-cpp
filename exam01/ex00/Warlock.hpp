#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
public:
	~Warlock();
	Warlock(std::string const & name, std::string const & title);

	std::string const & getName(void) const;
	std::string const & getTitle(void) const;
	
	void	setTitle(std::string const & title);
	void 	introduce() const;


private:
	Warlock();
	Warlock(Warlock const & src);
	Warlock & operator=(Warlock const & rhs);

	std::string _name;
	std::string	_title;
};

#endif