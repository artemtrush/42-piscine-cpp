#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(Span const & src);
	~Span();

	Span & operator=(Span const & rhs);

	void	addNumber(int n);
	int		shortestSpan(void);
	int		longestSpan(void);
	int & 	operator[](size_t it);

private:
	std::vector<int>	_array;

};

#endif