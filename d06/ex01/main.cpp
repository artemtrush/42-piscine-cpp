#include <iostream>
#include <ctime>

struct Raw
{
	char	s1[9];
	int		n;
	char	s2[9];
};

struct Data 
{
	std::string	s1;
	int			n;
	std::string	s2;
};

void generate(char str[])
{
	std::string pull = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 8; i++)
		str[i] = pull[std::rand() % 62];
	str[8] = 0;
}

void * serialize( void )
{
	Raw * data = new Raw;
	generate(data->s1);
	data->n = std::rand() % 100 + 1;
	generate(data->s2);

	std::cout << "Generated values" << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl << std::endl;

	return reinterpret_cast<void *>(data);
}

Data * deserialize( void * raw )
{
	Raw  * src = reinterpret_cast<Raw *>(raw);
	Data * data = new Data;
	data->s1 = static_cast<std::string>(src->s1);
	data->n = src->n;
	data->s2 = static_cast<std::string>(src->s2);
	delete src;
	return data;
}

int main(void)
{
	srand(time(0));
	void * ptr;
	Data * data;

	ptr = serialize();
	data = deserialize(ptr);
	ptr = NULL;
	
	std::cout << "Deserialized values" << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	delete data;
	data = NULL;
	return 0;
}