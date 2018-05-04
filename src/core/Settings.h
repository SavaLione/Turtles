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

std::string getSettingsString(char *block, char *value, char *ch_return_default);
int getSettings(char *block, char *value);
int getSettings(char *block, char *value, int i_return_default);
void setSettings(char *block, char *value, char *text);
bool checkFile(char *filename);
bool checkFile(std::string filename);
void createFile(char *file_name);
void createDir(std::string namedir);

#endif // SETTINGS_H
/** @} */