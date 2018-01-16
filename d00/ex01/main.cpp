#include <iostream>
#include <string>
#include "Society.class.hpp"

int		main(void)
{
	Society		array[8];
	std::string	buf;
	bool		exit;
	int			contact;
	int			index;

	exit = false;
	contact = 0;
	do
	{
		std::cout << "Enter a command [ADD | SEARCH | EXIT]: ";
		std::getline (std::cin, buf);
		if (std::cin.eof())
			return 0;
		if (buf == "ADD")
 		{
 			if (contact < 8)
 			{
 				if (!array[contact].fillFields())
 					return 0;
 				contact++;
 				std::cout << "Contact was successfully added." << std::endl;
 			}
 			else
 			{
 				std::cout << "Today's phonebook software can’t store more than 8 contacts!" << std::endl;
 			}
 		}
 		else if (buf == "SEARCH")
 		{
 			if (contact == 0)
 			{
 				std::cout << "Phonebook is empty." << std::endl;
 			}
 			else
 			{
				std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
				for (int i = 0; i < contact; i++)
				{
					array[i].printRow(i + 1);
				}
				std::cout << "Enter index: ";
				std::getline (std::cin, buf);
				if (std::cin.eof())
					return 0;
				index = (buf.length() == 1) ? buf[0] - 49 : -1;
				if (index < 0 || index >= contact)
				{
					std::cout << "Invalid index" << std::endl;
				}
				else
				{
					array[index].printFields();
				}
			}
 		}
 		else if (buf == "EXIT")
 		{
 			exit = true;
 		}
 		else
 		{
 			std::cout << "Invalid command" << std::endl;
 		}
	} while (!exit);
	return 0;
}