#include "span.hpp"

int main()
{
	std::cout << "Simply test:" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "Moulinette:" << std::endl;

	Span moul = Span(42000);

	try
	{
		for (int i = 0; i < 99999; i++)
			moul.addNumber(i);
	}
	catch (std::length_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << moul.shortestSpan() << std::endl;
	std::cout << moul.longestSpan() << std::endl;

	moul[0] = 42;
	std::cout << "moul[0]: " << moul[0] << std::endl;

	std::cout << std::endl << "Pls don't do that:" << std::endl;
	try
	{
		moul[42001] = 42;
	}
	catch (std::length_error e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;









}