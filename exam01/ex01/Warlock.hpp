#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <list>
#include <cstdlib>

class Warlock
{
public:
	~Warlock();
	Warlock(std::string const & name);

	std::string const & getName(void) const;
	void	addTitle(std::string const & title);
	void	removeTitle(std::string const & title);
	void	addQuote(std::string const & quote);
	void	removeQuote(std::string const & quote);

	void 	introduce() const;
	void	talk() const;


private:
	Warlock();
	Warlock(Warlock const & src);
	Warlock & operator=(Warlock const & rhs);

	std::string 			_name;
	std::list<std::string> 	_title;
	std::list<std::string>	_quotes;
};

#endif