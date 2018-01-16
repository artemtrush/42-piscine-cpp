#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <string>
# include "Brain.hpp"

class Human {

private:
	Brain const		marrow;

public:
	Human();
	~Human();
	std::string		identify(void);
	Brain const	&	getBrain(void);
};

#endif