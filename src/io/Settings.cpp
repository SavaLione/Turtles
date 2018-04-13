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

void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}

bool check_file(char *filename) {
	bool b_return = false;
	std::ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

void settings_initialization() {
	if (!check_file((char*)yenot::settings_file_name)) {
		setSettings("General", "initialization", "done");

		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_fastmode, "0");
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_noiseReduction, "1");
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_machineLearning, "1");

		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_log, "1");
		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_logTime, "1");
	}
}