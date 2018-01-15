#ifndef SOCIETY_CLASS_HPP
# define SOCIETY_CLASS_HPP
# include <iostream>
# include <string>

class Society {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	login;
	std::string	postal_address;
	std::string	email_address;
	std::string	phone_number;
	std::string	birthday_date;
	std::string	favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	int			setField(std::string *field, std::string name);
	std::string	trunc(std::string str);

public:
	Society();
	~Society();
	int			fillFields(void);
	void		printFields(void);
	void		printRow(int index);
};

#endif