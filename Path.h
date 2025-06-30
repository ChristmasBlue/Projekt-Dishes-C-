#pragma once

#include <string>
#include <filesystem>

#define PATH "users_Dish"//���� � ������

class Path
{
private:
	std::string pathName;
	const std::string path = PATH;
public:
	Path(std::string);//�����������
	bool checkPath(const std::string&);//�������� ����
	void createDir(const std::string&);//�������� �����
	std::string getPathName();//����������� ���� + �����
	std::string getPath();//����������� ����
};