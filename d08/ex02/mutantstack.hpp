#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <stack>

template< typename T >
class MutantStack : public std::stack<T>
{

public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(MutantStack const & src) : std::stack<T>(src) {}
	using std::stack<T>::operator=;

	/* container_type
	The second template parameter (Container)
	Type of the underlying containe
	*/

	typedef typename std::stack<T>::container_type::iterator iterator;

	/*
	template<class T, Class C = deque<T> >class std::stack {
	protected:
		C c;s
	*/

	iterator	begin()
	{
		return std::stack<T>::c.begin();
	}

	iterator  end()
	{
		return std::stack<T>::c.end();
	}
};

#endif