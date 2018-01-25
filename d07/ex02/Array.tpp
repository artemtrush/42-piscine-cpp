#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template< typename T = int >
class Array
{

public:

	Array< T >() : _array(NULL), _size(0) {}

	Array< T >(unsigned int n) : _array(NULL), _size(0)
	{
		if (n == 0)
			return;
		_array = new T[n];
		_size = static_cast<size_t>(n);
	}

	Array< T >(Array< T > const & src) : _array(NULL), _size(0)
	{
		*this = src;
	}

	Array< T > & operator=(Array< T > const & rhs)
	{
		if (this != &rhs)
		{
			if (this->_array)
			{
				delete [] this->_array;
				this->_array = NULL;
			}
			this->_size = rhs._size;
			if (this->_size > 0)
			{
				this->_array = new T[this->_size];
				for (size_t i = 0; i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
		}
		return *this;
	}

	~Array< T >()
	{
		if (this->_array)
		{
			delete [] this->_array;
			this->_array = NULL;
		}
	}

	T & operator[](size_t i)
	{
		if (i >= _size)
			throw std::exception();
		else
			return _array[i];
	}

	size_t	size(void) const
	{
		return _size;
	}

private:
	T 	* 	_array;
	size_t	_size;

};

#endif
