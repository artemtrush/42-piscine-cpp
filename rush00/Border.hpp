#ifndef BORDER_HPP
#define BORDER_HPP

#include <iostream>
#include "Object.hpp"

class Border : public Object
{

public:
	Border();
	~Border();
	Border(Border const & src);
	Border & operator=(Border const & rhs);

};

#endif
