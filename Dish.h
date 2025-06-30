#pragma once

#include <fstream>
#include <string>
#include <cstdlib>

#include "Path.h"

class Dish
{
public:
	Dish(std::string&, bool);//конструктор(передаём путь к файлу, передаём флаг(false-для записи,true-для чтения))
	~Dish();//деструктор
	void writeIngredient();
	void writeRecipe();
	void outputFile();//вывод файла на консоль
	bool checkStatus();

private:
	//Path path;
	std::fstream myFile;
	bool statusFile {false};//флаг файла(открыт на запись или нет)
	std::string nameDish;//название блюда
	std::string ingredient;//ингридиенты блюда
	std::string recipe;//рецепт блюда
	std::string lineInFile;//строка в файле(для вывода)
};