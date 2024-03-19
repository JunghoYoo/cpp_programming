#include "Add.h"
#include <iostream>

int main()
{
	int a, b, c;
	a = 2;
	b = 3;
	char d[16];

	c = lab1::Add(a, b);

	std::cout << c << std::endl;

	std::cin >> d;
}