#pragma once

#include <string>
#include <filesystem>

#define PATH "users_Dish"//путь к файлам

class Path
{
private:
	std::string pathName;
	const std::string path = PATH;
public:
	Path(std::string);//конструктор
	bool checkPath(const std::string&);//проверка пути
	void createDir(const std::string&);//создание папки
	std::string getPathName();//возвращение пути + имени
	std::string getPath();//возвращение пути
};