#include <iostream>
#include <fstream>
#include <sstream>

std::string strupper(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		*it = toupper(*it);
	return str;
}

bool replace(const char *input, const char *output,
	std::string s1, std::string s2)
{
	std::stringstream	buf;
	std::ifstream		inFile;
	std::ofstream		outFile;
	std::string			content;
	size_t				pos;
	size_t				offset;
	
	inFile.open(input);
	if (!inFile.is_open())
	 	return false;
	buf << inFile.rdbuf();
	content = buf.str();
	
	offset = 0;
	while ((pos = content.substr(offset).find(s1)) != std::string::npos)
	{
		content.replace(offset + pos, s1.length(), s2);
		offset = offset + pos + s2.length();
	}
	
	outFile.open(output);
	if (!outFile.is_open())
	 	return false;
	outFile << content;
	return true;
}

int main(int argc, char const *argv[])
{
	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return 0;
	}
	if (!replace(argv[1],(strupper(argv[1]) + ".replace").c_str(), argv[2], argv[3]))
		std::cout << "An error occurred." << std::endl;
	return 0;
}
