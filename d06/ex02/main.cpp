#include <iostream>
#include "Base.class.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base * generate( void )
{
	Base * ptr;
	int type = rand() % 3;
	if (type == 0)
	{
		std::cout << "A generated" << std::endl;
		ptr = new A;
	}
	else if (type == 1)
	{
		std::cout << "B generated" << std::endl;
		ptr = new B;
	}
	else
	{
		std::cout << "C generated" << std::endl;
		ptr = new C;
	}

	return ptr;
}

void identify_from_pointer( Base * p )
{
	if 		(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p )
{
	if 		(dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}


int main(void)
{
	srand(time(0));
	Base * ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	delete ptr;
	return 0;
}
