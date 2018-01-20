#ifndef OBJECT_HPP
#define OBJECT_HPP

#define MAP_WIDTH		200
#define MAP_HEIGHT		40
#define MAX_ENEMY_SIZE 	20
#define MAX_ENEMY 		(MAP_WIDTH / MAX_ENEMY_SIZE)
#define MAX_BULLET  	100
#define MIN_SPEED		5
#define PLAYER_COLOR 	0
#define BORDER_COLOR 	7
#define ENEMY_COLOR  	5
#define BULLET_COLOR 	1

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
