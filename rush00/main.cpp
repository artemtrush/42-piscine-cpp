#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "Border.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

Object * 		map[MAP_HEIGHT][MAP_WIDTH];
Enemy * 		enemy[MAX_ENEMY];
Bullet * 		bullet[MAX_BULLET];
unsigned int 	ammo;
unsigned int 	score;
int 		 	difficult;
int				setObject(Object * obj);
void 			enemyGenerator();
void 			bulletGenerator(Player * player);
void			movement();
void			print();
void			getKey(Player * player);
void 			loop();

void ncursesInit()
{
	initscr();
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	clear();
	refresh();
	nodelay(stdscr, TRUE);

	start_color();
	init_pair(PLAYER_COLOR, COLOR_BLUE, COLOR_BLUE);
	init_pair(BORDER_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(ENEMY_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(BULLET_COLOR, COLOR_RED, COLOR_RED);
	init_pair(13, COLOR_WHITE, COLOR_WHITE);
}

int main()
{
	std::srand(std::time(0));
	ncursesInit();
	loop();
	nodelay(stdscr, FALSE);
	clear();
    endwin();
    system("clear");
	std::cout << "GAME OVER" << std::endl << "YOUR SCORE: " << score << std::endl;
	return 0;
}

/*--------------------------------loop functions----------------------------------------*/

void loop()
{
	Border * border = new Border;
	Player * player = new Player((MAP_WIDTH + 1) / 2 - 4, MAP_HEIGHT - 9);
	memset(enemy, 0, sizeof(enemy));
	memset(bullet, 0, sizeof(bullet));
	ammo = MAX_BULLET;
	score = 0;
	difficult = 0;
	int counter = 1001;

	while (true)
	{
		memset(map, 0, sizeof(map));
		if (counter > 1000 / (difficult + 1))
		{
			enemyGenerator();
			counter = 0;
		}
		movement();
		getKey(player);
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
				ammo++;
			}
		if (setObject(player) == 0)
			break;
		print();
		refresh();
		usleep(DELAY);
		counter++;
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

void getKey(Player * player)
{
    int key = getch();
    switch (key)
    {
        case (KEY_UP):
        	player->move(0, -1);
        	break;
        case (KEY_DOWN):
        	player->move(0, 1);
        	break;
        case (KEY_LEFT):
        	player->move(-1, 0);
        	break;
        case (KEY_RIGHT):
        	player->move(1, 0);
        	break;
        case (32):
        	if (player->getY() > 3)
        		bulletGenerator(player);
        	break;
    }
}

void	print()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			if (map[i][j])
			{
				attron(COLOR_PAIR(map[i][j]->getColor()));
				mvprintw(i, MAP_OFFSET + j * 2, "  ");
				attroff(COLOR_PAIR(map[i][j]->getColor()));
			}
			else
			{
				attron(COLOR_PAIR(13));
				mvprintw(i, MAP_OFFSET + j * 2, "  ");
				attroff(COLOR_PAIR(13));
			}
	mvprintw(MAP_HEIGHT, MAP_OFFSET + 2, "SCORE: %d  ", score);
	mvprintw(MAP_HEIGHT, MAP_OFFSET + MAP_WIDTH * 2 - 10, "AMMO: %d  ", ammo);
}

void setNULL(Object * obj)
{
	if (!obj)
	 	return;
	int x;
	int y;
	int * array = obj->getBody();
	for (int i = 0; i < obj->getSize(); i += 2)
	{
		x = obj->getX() + array[i];
		y = obj->getY() + array[i + 1];
		if (map[y][x])
			map[y][x] = NULL;
	}
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
			if (obj->getColor() == ENEMY_COLOR && map[y][x]->getColor() == BORDER_COLOR)
			{
				score -= (score > 0) ? 1 : 0;
				difficult -= (difficult > 1) ? 2 : 0;
			}
			if (map[y][x]->getId() >= 0)
			{
				j = map[y][x]->getId();
				if (enemy[j]->takeDamage())
				{
					if (obj->getColor() == BULLET_COLOR)
					{
						score += 3;
						if (difficult + 2 < MIN_SPEED)
							difficult += 2;
					}
					setNULL(enemy[j]);
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
			if (rand() % 15 == 0)
				type = 3;
			else if (rand() % 5 == 0)
				type = 2;
			else
				type = 1;
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
			ammo--;
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
	{
		if (enemy[i])
		{
			if (rand() % (MIN_SPEED - difficult) == 0)
				enemy[i]->move(0, 1);
			if (rand() % ((MIN_SPEED - difficult) * 3) == 0)
			{
				if (enemy[i]->getX() < 3)
					enemy[i]->move(1, 0);
				else if (enemy[i]->getX() + enemy[i]->getWidth() > MAP_WIDTH - 3)
					enemy[i]->move(-1, 0);
				else
				{
					if (rand() % 2)
						enemy[i]->move(1, 0);
					else
						enemy[i]->move(-1, 0);
				}
			}
		}
	}
}
