#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		SuperMutant & operator=(SuperMutant const & rhs);
		~SuperMutant();

		void takeDamage(int);
};

#endif