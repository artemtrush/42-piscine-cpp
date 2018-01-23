#ifndef OBJECT_HPP
#define OBJECT_HPP

#define	MAP_OFFSET		100
#define MAP_WIDTH		100
#define MAP_HEIGHT		90
#define MAX_ENEMY_SIZE 	20
#define MAX_ENEMY 		(MAP_WIDTH / MAX_ENEMY_SIZE)
#define MAX_BULLET  	5
#define MIN_SPEED		50
#define DELAY			(6666)


#define PLAYER_COLOR 	1
#define BORDER_COLOR 	2
#define ENEMY_COLOR  	3
#define BULLET_COLOR 	4

class Object
{

protected:
	Object();
	Object(int x, int y, int color);
	int		_x;
	int		_y;
	int		_color;
	int		_size;
	int	*	_body;
	int		_id;

public:
	virtual ~Object();
	Object(Object const & src);
	Object & operator=(Object const & rhs);

	void	move(int x, int y);
	int		getX() const;
	int		getY() const;
	int		getColor() const;
	int		getSize() const;
	int	* 	getBody() const;
	int		getId();
	void 	setId(int id);
};

#endif
