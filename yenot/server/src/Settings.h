/**
	@file
	@brief Заголовочный файл модуля работы с ini файлами
	@author SavaLione
	@date 20 Apr 2018
*/
/**
	@defgroup settingsh Settings.h
	@ingroup yenot
	@{
*/
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

/**
	@brief Получить строку из файла настроек
	@param [in] block Блок файла настроек
	@param [in] value Искомая переменная
	@param [in] ch_return_default Значение, если переменная не найдена в файле настроек
	@return Строка из файла настроек
*/
std::string getSettingsString(char *block, char *value, char *ch_return_default);

/**
	@brief Получить число из файла настроек
	@param [in] block Блок файла настроек
	@param [in] value Искомая переменная
	@param [in] i_return_default Значение, если переменная не найдена в файле настроек
	@return Число  из файла настроек
*/
int getSettings(char *block, char *value, int i_return_default);

/**
	@brief Сохранить переменную в файл настроек
	@param [in] block Блок файла настроек
	@param [in] value Переменная
	@param [in] text Значение переменной
*/
void setSettings(char *block, char *value, char *text);

/**
	@brief Проверка файла
	@param [in] filename Название файла
	@return true - файл найден, false - файл не найден.
*/
bool checkFile(char *filename);
/**
	@brief Проверка файла
	@param [in] filename Название файла
	@return true - файл найден, false - файл не найден.
*/
bool checkFile(std::string filename);

/**
	@brief Функция для создания директории
	@param [in] namedir Путь и название директории
*/
void createDir(std::string namedir);

/**
	@brief Функция для создания файла
	@param [in] file_name Путь и название файла
*/
void createFile(char *file_name);

#endif // SETTINGS_H
/** @} */