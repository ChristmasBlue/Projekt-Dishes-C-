#pragma once

#include "Path.h"
#include "Dish.h"
#include "myTools.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <filesystem>

void run(std::string name)
{
	Path path(name);
	system("cls");
	if (!path.checkPath(path.getPath()))
	{
		path.createDir(path.getPath());
		path.createDir(path.getPathName());
		std::cout << "����� ���������� " << name << "!" << std::endl;
	}
	else if (!path.checkPath(path.getPathName()))
	{
		path.createDir(path.getPathName());
		std::cout << "����� ���������� " << name << "!" << std::endl;
	}
	else
	{
		std::cout << "����������� " << name << "!" << std::endl;
	}

	int command;
	std::string nameDish;
	for (;;)
	{
		std::cout << "�������:\n";
		std::cout << "������� '1' ����� �������� ������.\n";
		std::cout << "������� '2' ����� ����� ������ �� ��������.\n";
		std::cout << "������� '3' ����� ������� �������� ���� ��������.\n";
		std::cout << "������� '4' ����� ������� ������ �� ��������.\n";
		std::cout << "������� '0' ����� ����� �� ���������.\n";
		std::cout << "������� �������: ";
		std::cin >> command;
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			std::cout << "������� �������� �����: ";
			if (std::cin.peek() == '\n') 
			{
				std::cin.ignore();
			}
			std::getline (std::cin, nameDish);
			std::string pathNameDish = path.getPathName() + "\\" + nameDish + ".txt";
			if (std::filesystem::exists(pathNameDish))
			{
				int x;
				std::cout << "������ � ����� ��������� ��� ����������, ������ ������������ ��� ?\n";
				std::cout << "������� '1' ��� ���������� �������, '2' ��� ������: ";
				std::cin >> x;
				if (x == 2)
					break;
			}
			Dish dishAdd(pathNameDish, false);
			dishAdd.writeIngredient();
			dishAdd.writeRecipe();
			break;
		}
		case 2:
		{
			std::cout << "������� �������� �����: ";
			if (std::cin.peek() == '\n') 
			{
				std::cin.ignore();
			}
			std::getline(std::cin, nameDish);
			std::string pathCheck{ searchFile(path.getPathName(), nameDish) };
			if (pathCheck == "eror")
			{
				std::cout << "������ � ����� ��������� �� ������.\n";
				break;
			}
			Dish dishGet(pathCheck, true);
			dishGet.outputFile();
			system("pause");
			break;
		}
		case 3:
		{
			std::cout << "���� �����:\n";
			outAllNameFile(path.getPathName());
			system("pause");
			break;
		}
		case 4:
		{
			std::cout << "������� �������� �����, ������ �������� ������ �������: ";
			if (std::cin.peek() == '\n')
			{
				std::cin.ignore();
			}
			std::getline(std::cin, nameDish);
			deleteDish(path.getPathName() + "\\" + nameDish + ".txt");
			break;
		}
		default:
			std::cout << "������� �� ����������.\n";
			break;
		}
		system("cls");
	}
}
