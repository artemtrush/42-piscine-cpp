#include "Border.hpp"

Border::Border() : Object(0, 0, BORDER_COLOR) {
	int	counter;
	int	itr;
	this->_size = (MAP_WIDTH * 2 + (MAP_HEIGHT - 2) * 2) * 2;
	this->_body = new int [this->_size];

	itr = 0;
	counter = 0;
	for (int i = 0; i < MAP_WIDTH ; i++)
	{
		this->_body[itr] = counter++;
		this->_body[itr + 1] = 0;
		itr += 2;
	}
	counter = 0;
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		this->_body[itr] = counter++;
		this->_body[itr + 1] = MAP_HEIGHT - 1;
		itr += 2;
	}
	counter = 1;
	for (int i = 0; i < MAP_HEIGHT - 2; i++)
	{
		this->_body[itr] = 0;
		this->_body[itr + 1] = counter++;
		itr += 2;
	}
	counter = 1;
	for (int i = 0; i < MAP_HEIGHT - 2; i++)
	{
		this->_body[itr] = MAP_WIDTH - 1;
		this->_body[itr + 1] = counter++;
		itr += 2;
	}
}

Border::~Border() {}

Border::Border(Border const & src) : Object(src) {}

Border & Border::operator=(Border const & rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_color = rhs._color;
		this->_size = rhs._size;
		this->_body = rhs._body;
		this->_id = rhs._id;
	}
	return *this;
}

