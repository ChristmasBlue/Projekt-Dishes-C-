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
		std::cout << "Добро пожаловать " << name << "!" << std::endl;
	}
	else if (!path.checkPath(path.getPathName()))
	{
		path.createDir(path.getPathName());
		std::cout << "Добро пожаловать " << name << "!" << std::endl;
	}
	else
	{
		std::cout << "Приветствую " << name << "!" << std::endl;
	}

	int command;
	std::string nameDish;
	for (;;)
	{
		std::cout << "Команды:\n";
		std::cout << "Введите '1' чтобы добавить рецепт.\n";
		std::cout << "Введите '2' чтобы найти рецепт по названию.\n";
		std::cout << "Введите '3' чтобы вывести названия всех рецептов.\n";
		std::cout << "Введите '4' чтобы удалить рецепт по названию.\n";
		std::cout << "Введите '0' чтобы выйти из программы.\n";
		std::cout << "Введите команду: ";
		std::cin >> command;
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			std::cout << "Введите название блюда: ";
			if (std::cin.peek() == '\n') 
			{
				std::cin.ignore();
			}
			std::getline (std::cin, nameDish);
			std::string pathNameDish = path.getPathName() + "\\" + nameDish + ".txt";
			if (std::filesystem::exists(pathNameDish))
			{
				int x;
				std::cout << "Рецепт с таким названием уже существует, хотите перезаписать его ?\n";
				std::cout << "Введите '1' для перезаписи рецепта, '2' для отмены: ";
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
			std::cout << "Введите название блюда: ";
			if (std::cin.peek() == '\n') 
			{
				std::cin.ignore();
			}
			std::getline(std::cin, nameDish);
			std::string pathCheck{ searchFile(path.getPathName(), nameDish) };
			if (pathCheck == "eror")
			{
				std::cout << "Рецепт с таким названием не найден.\n";
				break;
			}
			Dish dishGet(pathCheck, true);
			dishGet.outputFile();
			system("pause");
			break;
		}
		case 3:
		{
			std::cout << "Ваши блюда:\n";
			outAllNameFile(path.getPathName());
			system("pause");
			break;
		}
		case 4:
		{
			std::cout << "Введите название блюда, рецепт которого хотите удалить: ";
			if (std::cin.peek() == '\n')
			{
				std::cin.ignore();
			}
			std::getline(std::cin, nameDish);
			deleteDish(path.getPathName() + "\\" + nameDish + ".txt");
			break;
		}
		default:
			std::cout << "Команда не распознана.\n";
			break;
		}
		system("cls");
	}
}
