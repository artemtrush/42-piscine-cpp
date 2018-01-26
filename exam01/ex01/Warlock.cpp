#include "Warlock.hpp"

Warlock::~Warlock() 
{
	std::cout << _name << ": Ahhh, I see it clearly. This is the plane of SUCK..." << std::endl;
}

Warlock::Warlock(std::string const & name) : _name(name)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName(void) const
{
	return _name;
}

void 	Warlock::introduce() const
{
	std::cout<<_name<<": I am "<<_name;
	for(std::list<std::string>::const_iterator it = _title.begin(); it != _title.end(); it++)
		std::cout<<", "<< *it;
	std::cout<<" ! And the mayor of a little village on the coast. Very scenic during springtime, you should visit sometime !"<<std::endl;
}

void	Warlock::addTitle(std::string const & title)
{
	_title.push_back(title);
}

void	Warlock::removeTitle(std::string const & title)
{
	_title.remove(title);
}

void	Warlock::addQuote(std::string const & quote)
{
	_quotes.push_back(quote);
}

void	Warlock::removeQuote(std::string const & quote)
{
	_quotes.remove(quote);
}

void	Warlock::talk() const
{
	if (_quotes.size() == 0)
		return;
	std::list<std::string>::const_iterator it = _quotes.begin();
	int pos = std::rand() % _quotes.size();
	while (pos-- > 0)
		it++;
	std::cout<< _name << ": "<< *it <<std::endl;
}