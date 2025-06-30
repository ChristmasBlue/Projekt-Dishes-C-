#pragma once

#include <fstream>
#include <string>
#include <cstdlib>

#include "Path.h"

class Dish
{
public:
	Dish(std::string&, bool);//�����������(������� ���� � �����, ������� ����(false-��� ������,true-��� ������))
	~Dish();//����������
	void writeIngredient();
	void writeRecipe();
	void outputFile();//����� ����� �� �������
	bool checkStatus();

private:
	//Path path;
	std::fstream myFile;
	bool statusFile {false};//���� �����(������ �� ������ ��� ���)
	std::string nameDish;//�������� �����
	std::string ingredient;//����������� �����
	std::string recipe;//������ �����
	std::string lineInFile;//������ � �����(��� ������)
};