#include "Warlock.hpp"

int main()
{
	Warlock richard("Richard");
	richard.addTitle("Chief Warlock of the Brothers of Darkness");
	richard.addTitle("Lord of the Thirteen Hells");
	richard.addTitle("Emperor of the Black");
	richard.addTitle("Lord of the Undead");
	richard.addTitle("Mistress of Magma");
	richard.introduce();
	richard.removeTitle("Mistress of Magma");
	richard.introduce();
	richard.addQuote("You\'ve just been Dick-rolled !");
	richard.addQuote("This day is fantastic ...");
	richard.addQuote("That orphanage attacked ME. It was self-defense !");
	richard.addQuote("You like what I do ?");
	richard.talk();
	richard.talk();
}
