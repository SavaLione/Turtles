/**
	@file
	@brief Модуль работы с ini файлами
	@author SavaLione
	@date 20 Apr 2018
*/
/**
	@defgroup settingscpp Settings.cpp
	@ingroup yenot
	@{
*/
#include <Windows.h>
#include <direct.h>
#include <fstream>

#include "..\core\Yenot.h"
#include "..\core\Logger.h"
#include "..\core\Settings.h"

using namespace std;
using namespace yenot;

/**
	@brief Получить строку из файла настроек
	@param [in] block Блок файла настроек
	@param [in] value Искомая переменная
	@param [in] ch_return_default Значение, если переменная не найдена в файле настроек
	@return Строка из файла настроек
*/
string getSettingsString(char *block, char *value, char *ch_return_default) {
	char text[BUFFER_SIZE];
	GetPrivateProfileString(block, value, ch_return_default, text, BUFFER_SIZE, FILE_NAME_CONFIG);
	return text;
}

/**
	@brief Получить число из файла настроек
	@param [in] block Блок файла настроек
	@param [in] value Искомая переменная
	@param [in] i_return_default Значение, если переменная не найдена в файле настроек
	@return Число  из файла настроек
*/
int getSettings(char *block, char *value, int i_return_default) {
	return GetPrivateProfileInt(block, value, i_return_default, FILE_NAME_CONFIG);
}

/**
	@brief Сохранить переменную в файл настроек
	@param [in] block Блок файла настроек
	@param [in] value Переменная
	@param [in] text Значение переменной
*/
void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, FILE_NAME_CONFIG);
}

/**
	@brief Проверка файла
	@param [in] filename Название файла
	@return true - файл найден, false - файл не найден.
*/
bool checkFile(char *filename) {
	bool b_return = false;
	ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}
/**
	@brief Проверка файла
	@param [in] filename Название файла
	@return true - файл найден, false - файл не найден.
*/
bool checkFile(string filename) {
	bool b_return = false;
	ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

/**
	@brief Функция для создания директории
	@param [in] namedir Путь и название директории
*/
void createDir(string namedir) {
	///	Если успешно создали директорию, то:
	///
	///		Вывод в лог, что получилось создать директорию
	///
	/// иначе:
	///
	///		Вывод в лог, что не получилось создать директорию
	///
	///		Возможно это связано с тем, что нет прав на создание директории или директория уже есть
	if ((_mkdir(namedir.c_str())) == 0) {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_CREATE_DIR);
	} else {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_CREATE_DIR_NOT);
	}
}

/**
	@brief Функция для создания файла
	@param [in] file_name Путь и название файла
*/
void createFile(char *file_name) {
	ofstream fout(file_name);
	fout.close();
}
/** @} */