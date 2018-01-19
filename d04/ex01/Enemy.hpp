#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
	private:
		Enemy();

	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		Enemy & operator=(Enemy const & rhs);
		virtual ~Enemy();

		std::string const & getType() const;
		int getHP() const;

		virtual void takeDamage(int);

	protected:
		int					_hp;
		std::string			_type;
};

#endif