/**
	\file
	\brief פאיכ  (((O__O))).
	\author SavaLione
*/
#include <Windows.h>
#include <fstream>
#include <string>

#include "..\core\Yenot.h"
#include "Settings.h"

template <typename T>
bool check_file(T filename);



std::string getSettingsString(char *block, char *value) {
	char text[yenot::buffer_size];
	GetPrivateProfileString(block, value, yenot::ch_default_value, text, yenot::buffer_size, yenot::settings_file_name);
	return text;
}
int getSettingsInt(char *block, char *value) {
	int i_ret = GetPrivateProfileInt(block, value, yenot::i_return, yenot::settings_file_name);;
	return i_ret;
}


void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}

template <typename T>
bool check_file(T filename) {
	bool b_return = false;
	std::ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

void settings_initialization() {
	if (!check_file(yenot::settings_file_name)) {
		setSettings("General", "initialization", "done");
	}
}