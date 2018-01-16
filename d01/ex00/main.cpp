#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony*	Pinkie_Pie = new Pony("Pinkie Pie");
	delete	Pinkie_Pie;
}

void	ponyOnTheStack()
{
	Pony Fluttershy = Pony("Fluttershy");
}

int	main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}