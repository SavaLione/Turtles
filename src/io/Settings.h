/**
	\file
	\brief Описание
	\author SavaLione
*/
#ifndef SETTINGS_H
#define SETTINGS_H

std::string getSettingsString(char *block, char *value);
int getSettingsInt(char *block, char *value);
void setSettings(char *block, char *value, char *text);

template <typename T>
bool check_file(T filename);

void settings_initialization();

#endif // SETTINGS_H