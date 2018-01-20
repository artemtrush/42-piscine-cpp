#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "Border.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

Object * map[MAP_HEIGHT][MAP_WIDTH];
Enemy * enemy[MAX_ENEMY];
Bullet * bullet[MAX_BULLET];

void	print()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			if (map[i][j])
				mvprintw(i, j, "0");
			else
				mvprintw(i, j, " ");
}

int	setObject(Object * obj)
{
	if (!obj)
	 	return 1;
	int x;
	int y;
	int j;
	int * array = obj->getBody();
	for (int i = 0; i < obj->getSize(); i += 2)
	{
		x = obj->getX() + array[i];
		y = obj->getY() + array[i + 1];
		if (!map[y][x])
			map[y][x] = obj;
		else
		{
			if (map[y][x]->getId() >= 0)
			{
				j = map[y][x]->getId();
				if (enemy[j]->takeDamage())
				{
					delete enemy[j];
					enemy[j] = NULL;
				}
			}
			for (j = i - 2; j >= 0; j -= 2)
			{
				x = obj->getX() + array[j];
				y = obj->getY() + array[j + 1];
				map[y][x] = NULL;
			}
			return 0;
		}
	}
	return 1;
}

void 	enemyGenerator()
{
	int type;
	int	pos = (MAP_WIDTH - 2) / MAX_ENEMY;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (!enemy[i])
		{
			type = rand() % 3 + 1;
			enemy[i] = new Enemy(pos * i + 1, 1, type);
			enemy[i]->setId(i);
			enemy[i]->move(rand() % (pos - enemy[i]->getWidth()), 0);
		}
	}
}

void 	bulletGenerator(Player * player)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (!bullet[i])
		{
			bullet[i] = new Bullet(player->getX() + 3, player->getY() - 1);
			return;
		}
	}
}

void	movement()
{
	for (int i = 0; i < MAX_BULLET; i++)
		if (bullet[i])
			bullet[i]->move(0, -1);
	for (int i = 0; i < MAX_ENEMY; i++)
		if (enemy[i])
			if (rand() % MIN_SPEED == 0)
				enemy[i]->move(0, 1);

}

void loop()
{
	Border * border = new Border;
	Player * player = new Player((MAP_WIDTH + 1) / 2 - 4, MAP_HEIGHT - 9);
	memset(enemy, 0, sizeof(enemy));
	memset(bullet, 0, sizeof(bullet));

	while (true)
	{
		memset(map, 0, sizeof(map));
		enemyGenerator();
		movement();
		setObject(border);
		for (int i = 0; i < MAX_ENEMY; i++)
			if (setObject(enemy[i]) == 0)
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		for (int i = 0; i < MAX_BULLET; i++)
			if (setObject(bullet[i]) == 0)
			{
				delete bullet[i];
				bullet[i] = NULL;
			}
		if (setObject(player) == 0)
			break;
		print();
		refresh();
		usleep(100000);
	}

	for (int i = 0; i < MAX_ENEMY; i++)
		if (enemy[i])
			delete enemy[i];
	for (int i = 0; i < MAX_BULLET; i++)
		if (bullet[i])
			delete bullet[i];
	delete border;
	delete player;
}

int main()
{
	std::srand(std::time(0));
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	clear();
	refresh();
	loop();
	refresh();
	std::cout << "GAME OVER" << std::endl;
	return 0;
}