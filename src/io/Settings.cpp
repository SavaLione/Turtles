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



std::string getSettingsString(char *block, char *value) {
	char text[yenot::buffer_size];
	GetPrivateProfileString(block, value, yenot::ch_default_value, text, yenot::buffer_size, yenot::settings_file_name);
	return text;
}

int getSettings(char *block, char *value) {
	return GetPrivateProfileInt(block, value, yenot::i_return, yenot::settings_file_name);
}

template <typename T, typename U, typename V>
void setSettings(T const block, U const  value, V const text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}
template <>
void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}

template <typename T>
bool check_file(T const &filename) {
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

		setSettings(yenot::settings_block_core, yenot::settings_value_fastmode, "0");
		setSettings(yenot::settings_block_core, yenot::settings_value_noiseReduction, "1");
		setSettings(yenot::settings_block_core, yenot::settings_value_machineLearning, "1");

		setSettings(yenot::settings_block_logger, yenot::settings_value_log, "1");
		setSettings(yenot::settings_block_logger, yenot::settings_value_logTime, "1");
	}
}



/*
template <typename T>
std::string getSettingsString(T const &block, T const &value) {
char text[yenot::buffer_size];
GetPrivateProfileString(block, value, yenot::ch_default_value, text, yenot::buffer_size, yenot::settings_file_name);
return text;
}


//return GetPrivateProfileInt(block, value, yenot::i_return, yenot::settings_file_name);

template <typename T>
int getSettingsInt(T const block) {
return T;
}
*/