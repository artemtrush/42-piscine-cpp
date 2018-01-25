#include "mutantstack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	std::cout << "push 5" << std::endl;
	mstack.push(5);
	std::cout << "push 17" << std::endl;
	mstack.push(17);
	std::cout << "top:" << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "pop" << std::endl;
	mstack.pop();
	std::cout << "size:" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "push 3" << std::endl;
	mstack.push(3);
	std::cout << "push 5" << std::endl;
	mstack.push(5);
	std::cout << "push 737" << std::endl;
	mstack.push(737);
	std::cout << "push 42" << std::endl;
	mstack.push(42);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "values:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Assign:" << std::endl;
	MutantStack<int> nst = mstack;
	std::cout << mstack.top() << std::endl;
	std::cout << nst.top() << std::endl;
	return 0;
}