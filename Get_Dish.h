#pragma once
#include <fstream>
#include <string>
#include "Path.h"

class GetDish
{
public:
	GetDish(std::string&);
	~GetDish();
	void outputFile();//����� ����� �� �������
	bool checkStatus();

private:
	bool statusFile;//���� �����(������ �� ������ ��� ���)
	std::string namePath;//���� � �����
	std::ifstream myFile;
	std::string lineInFile;//������ � �����(��� ������)
};