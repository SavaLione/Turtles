#include <Windows.h>

int get_settings(char* ch_block, char* ch_value) {
	int i_ret = -1;
	GetPrivateProfileInt (
		ch_block,
		ch_value,
		i_ret,
		"turtle.ini"
	);
}