#pragma once
#include <fstream>
#include <string>
#include "Path.h"

class GetDish
{
public:
	GetDish(std::string&);
	~GetDish();
	void outputFile();//вывод файла на консоль
	bool checkStatus();

private:
	bool statusFile;//флаг файла(открыт на запись или нет)
	std::string namePath;//путь к файлу
	std::ifstream myFile;
	std::string lineInFile;//строка в файле(для вывода)
};