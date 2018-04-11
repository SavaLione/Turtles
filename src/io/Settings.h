/**
	\file
	\brief Описание
	\author SavaLione
*/
#ifndef SETTINGS_H
#define SETTINGS_H

int get_settings(char* ch_block, char* ch_value);
int get_settings(char* ch_value);
bool get_settings();

template <typename T>
bool check_file(T filename);

#endif // SETTINGS_H