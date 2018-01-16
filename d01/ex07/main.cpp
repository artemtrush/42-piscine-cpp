#include <iostream>
#include <fstream>

bool fileExists(std::string filename)
{
	std::ifstream ifl(filename);
	return ifl;
}

int main(int argc, char const *argv[])
{
	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
		return 0;
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!fileExists(filename))
		return 0;

	std::ifstream
	file.open();

	std::cout << "kekke";

	return 0;
}