/**
	\file
	\brief פאיכ  ((O__O)).
	\author SavaLione
*/
#include <Windows.h>
#include <fstream>

#include "..\core\Yenot.h"

template <typename T>
bool check_file(T filename);

int get_settings(char* ch_block, char* ch_value) {
	int i_ret = yenot::i_return;
	GetPrivateProfileInt (
		ch_block,
		ch_value,
		i_ret,
		yenot::settings_file_name
	);
	return i_ret;
}

int get_settings(char* ch_value) {
	int i_ret = yenot::i_return;
	GetPrivateProfileInt(
		yenot::ch_default_block,
		ch_value,
		i_ret,
		yenot::settings_file_name
	);
	return i_ret;
}

bool get_settings() {
	return check_file(yenot::settings_file_name);
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