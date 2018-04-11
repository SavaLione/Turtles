/**
	\file
	\brief פאיכ  ((O__O)).
	\author SavaLione
*/
#include <Windows.h>
#include <fstream>

#include "..\core\Yenot.h"
#include "Settings.h"

template <typename T>
bool check_file(T filename);

template <typename T>
int get_settings(T block, T value) {
	int i_ret = yenot::i_return;
	GetPrivateProfileInt (
		block,
		value,
		i_ret,
		yenot::settings_file_name
	);
	return i_ret;
}

template <typename T>
int get_settings(T value) {
	int i_ret = yenot::i_return;
	GetPrivateProfileInt(
		yenot::ch_default_block,
		value,
		i_ret,
		yenot::settings_file_name
	);
	return i_ret;
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
		std::ofstream fout(yenot::settings_file_name);
		fout << "";
		fout.close();
	}
}