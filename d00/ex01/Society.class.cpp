#include "Society.class.hpp"

Society::Society (void) {}

Society::~Society (void) {}

int			Society::setField(std::string *field, std::string name)
{
	std::cout << "Enter the " << name << ": ";
	std::cin >> *field;
	std::cin.clear(); 
	std::cin.ignore(10000, '\n');
	if (std::cin.eof())
		return 0;
	return 1;
}

int			Society::fillFields(void)
{
	if (!setField(&first_name, "first name"))
		return 0;
	if (!setField(&last_name, "last name"))
		return 0;
	if (!setField(&nickname, "nickname"))
		return 0;
	if (!setField(&login, "login"))
		return 0;
	if (!setField(&postal_address, "postal address"))
		return 0;
	if (!setField(&email_address, "email address"))
		return 0;
	if (!setField(&phone_number, "phone number"))
		return 0;
	if (!setField(&birthday_date, "birthday date"))
		return 0;
	if (!setField(&favorite_meal, "favorite meal"))
		return 0;
	if (!setField(&underwear_color, "underwear color"))
		return 0;
	if (!setField(&darkest_secret, "darkest secret"))
		return 0;
	return 1;
}

void		Society::printFields(void)
{
	std::cout << "first name: "<< first_name << std::endl;
	std::cout << "last name: "<< last_name << std::endl;
	std::cout << "nickname: "<< nickname << std::endl;
	std::cout << "login: "<< login << std::endl;
	std::cout << "postal address: "<< postal_address << std::endl;
	std::cout << "email address: "<< email_address << std::endl;
	std::cout << "phone number: "<< phone_number << std::endl;
	std::cout << "birthday date: "<< birthday_date << std::endl;
	std::cout << "favorite meal: "<< favorite_meal << std::endl;
	std::cout << "underwear color: "<< underwear_color << std::endl;
	std::cout << "darkest secret: "<< darkest_secret << std::endl;
	std::cout << std::endl;
}

std::string	Society::trunc(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str = str + '.';
	}
	else
	{
		int size = 10 - str.length();
		while (size-- > 0)
			str = ' ' + str;
	}
	return str;
}

void		Society::printRow(int index)
{
	std::cout << "|" << trunc(std::to_string(index));
	std::cout << "|" << trunc(first_name);
	std::cout << "|" << trunc(last_name);
	std::cout << "|" << trunc(nickname);
	std::cout << "|" << std::endl;
}