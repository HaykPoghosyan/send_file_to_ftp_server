// help_system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "application.h"

int main(int argc, char * argv[])
{

	application* app = new application(argc, argv);
	if (!app->exec()) {
		return 1;
	}

	for (int i = 0; i < argc; i++) {
		std::cout << "argc " << i << " = " << argc << " argv = " << argv[i] << std::endl;
	}

	return 0;
}

