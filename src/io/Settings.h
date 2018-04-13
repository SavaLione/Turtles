/**
	\file
	\brief Описание
	\author SavaLione
*/
#ifndef SETTINGS_H
#define SETTINGS_H

std::string getSettingsString(char *block, char *value);

int getSettings(char *block, char *value);





template <typename T, typename U, typename V>
void setSettings(T const block, U const  value, V const text);
template <>
void setSettings(char *block, char *value, char *text);

template <typename T>
bool check_file(T const &filename);

void settings_initialization();

#endif // SETTINGS_H