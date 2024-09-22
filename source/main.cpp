#include "window.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << std::endl;

	Window window;
	window.link();
	window.run();
}
