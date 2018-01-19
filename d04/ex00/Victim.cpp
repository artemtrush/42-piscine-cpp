#include "Victim.hpp"

Victim::Victim()
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & stream, Victim const & rhs)
{
	stream << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return stream;
}

std::string	Victim::getName(void) const
{
	return this->_name;
}

void 		Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}
