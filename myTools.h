#pragma once

#include <filesystem>
#include <string>
#include <iostream>

std::string searchFile(const std::filesystem::path&, std::string& ); //����� ����� �� ��������(����� ������� �� ��������)

void outAllNameFile(const std::filesystem::path&);//����� ���� ������ ��� ���������� (����� �������� ��������)

void deleteDish(const std::filesystem::path&);//�������� ����� �� ��������