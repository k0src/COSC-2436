#include <iostream>
#include "LinkedList.h"

int main() 
{
	LinkedList belt1; // Belt with defective toys
	LinkedList belt2; // Replacement belt

	int a = 0, b = 2;

	belt1.addToyToEnd("Bear", 50);
	belt1.addToyToEnd("Doll", 30);
	belt1.addToyToEnd("Action Figure", 100); // replace
	belt1.addToyToEnd("Legos", 20); // replace 
	belt1.addToyToEnd("Car", 10); // replace
	belt1.addToyToEnd("Drums", 200);

	std::cout << "Original belt: \n";
	belt1.printBelt();
	std::cout << std::endl;

	belt2.addToyToEnd("Ball", 10);
	belt2.addToyToEnd("Wand", 20);
	belt2.addToyToEnd("Wooden Sword", 50);

	belt1.replaceBelt(a, b, belt2);

	std::cout << "Belt with replaced toys: \n";
	belt1.printBelt();

	return 0;
}