#include "myTools.h"
#include <string>

std::string searchFile(const std::filesystem::path& directory, std::string& nameFile)
{
    nameFile = nameFile + ".txt";
    for (const auto& entry : std::filesystem::directory_iterator(directory)) 
    {
        if (entry.is_regular_file() && entry.path().filename() == nameFile) //если это не папка и название совпадает
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
        if (entry.is_regular_file()) //если это не папка выводим название без расширения
        {
            std::cout << entry.path().stem().string() << std::endl;
        }
    }
}

void deleteDish(const std::filesystem::path& directory)
{
    if (std::filesystem::exists(directory)) {
        std::filesystem::remove(directory);
        std::cout << "Рецепт удалён." << std::endl;
        system("pause");
    }
    else {
        std::cout << "Ошибка в названии блюда, повторите попытку." << std::endl;
        system("pause");
    }
}