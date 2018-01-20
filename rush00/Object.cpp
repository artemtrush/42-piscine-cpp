#include "Object.hpp"

Object::Object() {}

Object::Object(int x, int y, int color) :
	_x(x), _y(y), _color(color), _id(-1) {}

Object::~Object() {
	delete [] this->_body;
}

Object::Object(Object const & src)
{
	*this = src;
}

Object & Object::operator=(Object const & rhs)
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

int		Object::getX() const { return this->_x; }
int		Object::getY() const { return this->_y; }
int		Object::getColor() const { return this->_color; }
int		Object::getSize() const { return this->_size; }
int *	Object::getBody() const { return this->_body; }

void	Object::move(int x, int y)
{
	this->_x += x;
	this->_y += y;
}

int	Object::getId()
{
	return this->_id;
}

void Object::setId(int id)
{
	this->_id = id;
}