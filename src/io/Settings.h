/**
	\file
	\brief Описание
	\author SavaLione
*/
#ifndef SETTINGS_H
#define SETTINGS_H

std::string getSettingsString(char *block, char *value);

int getSettings(char *block, char *value);

void setSettings(char *block, char *value, char *text);

bool check_file(char *filename);

void settings_initialization();

#endif // SETTINGS_H