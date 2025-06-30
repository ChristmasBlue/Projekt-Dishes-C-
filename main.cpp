#include "LogicProg.h"
#include <iostream> 
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name;
	std::cout << "¬ведите им€ пользовател€: ";
	std::getline(std::cin, name);
	run(name);
	return 0;
}