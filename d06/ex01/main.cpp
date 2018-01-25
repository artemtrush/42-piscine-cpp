#include <iostream>
#include <ctime>

struct Data 
{
	std::string	s1;
	int			n;
	std::string	s2;
};


void * serialize( void )
{
	char 	pull[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char	*ptr = new char[20];

	std::cout << "Generated values" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		ptr[i] = pull[std::rand() % 62];
		std::cout << ptr[i];
	}
	std::cout << std::endl;
	
	int	tmp = rand() % 100 + 1;
	*(reinterpret_cast<int *>(&ptr[8])) = tmp;
	std::cout << tmp << std::endl;

	for (int i = 12; i < 20; i++)
	{
		ptr[i] = pull[std::rand() % 62];
		std::cout << ptr[i];
	}
	std::cout << std::endl << std::endl;
	return reinterpret_cast<void *>(ptr);
}

Data * deserialize( void * raw )
{
	Data * data = new Data;

	data->s1.assign(reinterpret_cast<char *>(raw), 8);
	data->n = *reinterpret_cast<int *>(&reinterpret_cast<char *>(raw)[8]);
	data->s2.assign(&reinterpret_cast<char *>(raw)[12], 8);
	return data;
}

int main(void)
{
	srand(time(0));
	void * ptr;
	Data * data;

	ptr = serialize();
	data = deserialize(ptr);
		
	std::cout << "Deserialized values" << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	delete data;
	delete reinterpret_cast<char *>(ptr);
	return 0;
}