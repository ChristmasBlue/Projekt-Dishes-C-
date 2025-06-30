#include "Get_Dish.h"
#include <iostream>

GetDish::GetDish(std::string& name) : namePath(name)
{
	myFile.open(namePath);// Открываем файл для чтения
	if (!myFile.is_open())
	{
		statusFile = false;
	}
	else
	{
		statusFile = true;
	}
}

GetDish::~GetDish()
{
	if (statusFile)
		myFile.close();
}

void GetDish::outputFile()
{
	while (std::getline(myFile, lineInFile))
	{
		std::cout << lineInFile << std::endl;
	}
}

bool GetDish::checkStatus()
{
	return statusFile;
}