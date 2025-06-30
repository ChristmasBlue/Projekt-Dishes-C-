#include "Dish.h"
#include <iostream>
//#include <limits>

Dish::Dish(std::string& name, bool fileInOut) : nameDish(name)
{
	if (fileInOut)
	{
		myFile.open(nameDish, std::ios::in);// ��������� ���� ��� ������
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
		myFile.open(nameDish, std::ios::out);// ��������� ���� ��� ������
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
		std::cout << "������� �����������:\n";
		myFile << "����������� :\n";
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
		std::cout << "�� ������� ������� ���� ��� ������.\n";
		system("pause");
	}
}

void Dish::writeRecipe()
{
	if (statusFile)
	{
		std::cout << "������� ������:\n";
		myFile << "������ :\n";
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
		std::cout << "�� ������� ������� ���� ��� ������.\n";
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