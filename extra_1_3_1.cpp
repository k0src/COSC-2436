#include <iostream>

int main(int argc, char** argv) 
{
	// prints # of args and all args
	
	std::cout << "args: " << argc << std::endl;

	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	return 0;
}
