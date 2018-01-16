#ifndef PONY_HPP
# define PONY_HPP
# include <string>

class Pony {

private:
	std::string name;

public:
	Pony(std::string str);
	~Pony();
};

#endif