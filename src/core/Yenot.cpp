/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>

#include "Yenot.h"
#include "..\io\Settings.h"
#include "..\io\Logger.h"

using namespace std;

int main(int argc, char* argv[]) {
	settings_initialization();

	logger((char*)"some", (char*)"some");

	system("pause");
    return 0;
}