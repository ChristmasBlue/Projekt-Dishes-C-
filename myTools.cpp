#include "myTools.h"
#include <string>

std::string searchFile(const std::filesystem::path& directory, std::string& nameFile)
{
    nameFile = nameFile + ".txt";
    for (const auto& entry : std::filesystem::directory_iterator(directory)) 
    {
        if (entry.is_regular_file() && entry.path().filename() == nameFile) //���� ��� �� ����� � �������� ���������
        {
            return entry.path().string();
        }
    }
    return "eror";
}

void outAllNameFile(const std::filesystem::path& directory)
{
    for (const auto& entry : std::filesystem::directory_iterator(directory)) 
    {
        if (entry.is_regular_file()) //���� ��� �� ����� ������� �������� ��� ����������
        {
            std::cout << entry.path().stem().string() << std::endl;
        }
    }
}

void deleteDish(const std::filesystem::path& directory)
{
    if (std::filesystem::exists(directory)) {
        std::filesystem::remove(directory);
        std::cout << "������ �����." << std::endl;
        system("pause");
    }
    else {
        std::cout << "������ � �������� �����, ��������� �������." << std::endl;
        system("pause");
    }
}