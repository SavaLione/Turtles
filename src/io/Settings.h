/**
	\file
	\brief Описание
	\author SavaLione
*/
#ifndef SETTINGS_H
#define SETTINGS_H

template <typename T>
int get_settings(T block, T value);

template <typename T>
int get_settings(T value);

template <typename T>
bool check_file(T filename);

void settings_initialization();

#endif // SETTINGS_H