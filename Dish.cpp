#include "Dish.h"
#include <iostream>
//#include <limits>

Dish::Dish(std::string& name, bool fileInOut) : nameDish(name)
{
	if (fileInOut)
	{
		myFile.open(nameDish, std::ios::in);// Открываем файл для записи
		if (!myFile.is_open())
		{
			statusFile = false;
		}
		else
		{
			statusFile = true;
		}
	}
	else if (!fileInOut)
	{
		myFile.open(nameDish, std::ios::out);// Открываем файл для чтения
		if (!myFile.is_open())
		{
			statusFile = false;
		}
		else
		{
			statusFile = true;
		}
	}
}

Dish::~Dish()
{
	if (statusFile)
		myFile.close();
}

void Dish::writeIngredient()
{
	if (statusFile)
	{
		std::cout << "Введите ингредиенты:\n";
		myFile << "Ингридиенты :\n";
		std::cout << "- ";
		if (std::cin.peek() == '\n') 
		{
			std::cin.ignore();
		}
		while (std::getline(std::cin, ingredient))
		{
			if (ingredient == "")
			{
				break;
			}
			myFile <<"- "<< ingredient << '\n';
			std::cout << "- ";
		}
	}
	else
	{
		std::cout << "Не удалось открыть файл для записи.\n";
		system("pause");
	}
}

void Dish::writeRecipe()
{
	if (statusFile)
	{
		std::cout << "Введите рецепт:\n";
		myFile << "Рецепт :\n";
		if (std::cin.peek() == '\n') 
		{
			std::cin.ignore();
		}
		while (std::getline(std::cin, recipe))
		{
			if (recipe == "")
			{
				break;
			}
			myFile << recipe << '\n';
		}
	}
	else
	{
		std::cout << "Не удалось открыть файл для записи.\n";
		system("pause");
	}
}

void Dish::outputFile()
{
	while (std::getline(myFile, lineInFile))
	{
		std::cout << lineInFile << std::endl;
	}
}

bool Dish::checkStatus()
{
	return statusFile;
}