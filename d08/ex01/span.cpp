#include "span.hpp"
#include <sstream>
#include <algorithm>
#include <climits>

Span::Span()
{
	_array.reserve(0);
}

Span::Span(unsigned int N)
{
	_array.reserve(N);
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_array = rhs._array;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_array.capacity() - _array.size() <= 0)
	{
		std::stringstream exc;
		exc << "There are already " << _array.size() << " of " << _array.capacity() << " integers stored.";
		throw std::length_error(exc.str());
	}
	_array.push_back(n);
}

int		Span::shortestSpan(void)
{
	if (_array.size() < 2)
		throw std::logic_error("Not enough values stored.");
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	int min = INT_MAX;
	for (std::vector<int>::const_iterator it = tmp.begin(); it < tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return min;
}

int		Span::longestSpan(void)
{
	if (_array.size() < 2)
		throw std::logic_error("Not enough values stored.");
	return *std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end());
}

int & Span::operator[](size_t it)
{
	if (it >= _array.size())
		throw std::length_error("Invalid index.");
	return _array.at(it);
}