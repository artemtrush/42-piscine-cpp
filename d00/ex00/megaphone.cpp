#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	std::string tmp;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			tmp = argv[i];
			for (std::string::iterator it = tmp.begin(); it != tmp.end(); it++)
			{
    			*it = toupper(*it);
			}
			std::cout << tmp;
		}
		std::cout << std::endl;
	}
	return 0;
}