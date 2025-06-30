#include "Path.h"
#include <filesystem>
#include <iostream>

Path::Path(std::string namestr)
{
	pathName = path + "\\" + namestr;
}

bool Path::checkPath(const std::string& path)
{
	if (std::filesystem::exists(path))
	{
		if (std::filesystem::is_directory(path))
		{
			//std::cout << "Пользователь существует.\n" ;
			return true;
		}
		else
		{
			std::cout << "it's not directory\n";
			return false;
		}
	}
	return false;
}

void Path::createDir(const std::string& path)
{
	if(std::filesystem::create_directory(path))
	{
		//std::cout << "Пользователь Создан.\n";
	}
	else
	{
		std::cout << "directory is not created\n";
	}
}

std::string Path::getPathName()
{
	return pathName;
}

std::string Path::getPath()
{
	return path;
}
