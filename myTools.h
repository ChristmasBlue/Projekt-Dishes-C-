#pragma once

#include <filesystem>
#include <string>
#include <iostream>

std::string searchFile(const std::filesystem::path&, std::string& ); //поиск файла по названию(поиск рецепта по названию)

void outAllNameFile(const std::filesystem::path&);//вывод всех файлов без расширений (вывод названий рецептов)

void deleteDish(const std::filesystem::path&);//удаление файла по названию