#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
	private:
		Character();
		std::string			_name;
		int					_ap;
		AWeapon*			_weapon;

	public:
		Character(std::string const & name);
		Character(Character const & src);
		Character & operator=(Character const & rhs);
		~Character();

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const & getName() const;
		int					getAP() const;
		AWeapon *			getWeapon() const;
};

std::ostream & operator<<(std::ostream & stream, Character const & rhs);

#endif