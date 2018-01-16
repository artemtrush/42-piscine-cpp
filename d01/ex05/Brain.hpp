#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {
private:
	int iq;
	
public:
	Brain();
	~Brain();
	std::string identify(void) const;
};

#endif