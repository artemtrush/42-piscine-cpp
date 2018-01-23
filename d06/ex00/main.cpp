#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		double db;
		if (strlen(argv[1]) == 1 && !isdigit(argv[1][0]))
			db = static_cast<double>(argv[1][0]);
		else
			db = atof(argv[1]);

		int it = static_cast<int>(db);
		char ch = static_cast<char>(db);
		float fl = static_cast<float>(db);

		if (isnan(db) || isinf(db))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else if ((strlen(argv[1]) == 1 && !isdigit(argv[1][0])) ||
				(strlen(argv[1]) >= 1 && isdigit(argv[1][0])) ||
				(strlen(argv[1]) >= 2 && (argv[1][0] == '-' || argv[1][0] == '+') && isdigit(argv[1][1])))
		{
			if (it < -128 || it > 127)
				std::cout << "char: impossible" << std::endl;
			else if (isprint(ch))
				std::cout << "char: \'" << ch << "\'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << it << std::endl;
		}
		else
		{
			std::cout << "Invalid format" << std::endl;
			return 0;
		}
  		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(1) << fl << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << db << std::endl;
		return 0;
	}
	std::cout << "Usage: ./convert argument" << std::endl;
	return 0;
}