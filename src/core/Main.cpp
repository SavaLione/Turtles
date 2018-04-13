/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>
#include <opencv2\opencv.hpp>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include <string>

#include "Yenot.h"
#include "..\io\Settings.h"
#include "..\io\Logger.h"

using namespace std;

int main(int argc, char* argv[]) {
	settings_initialization();

	string s = getSettingsString("General", "default");

	int i = getSettingsInt("General", "int");
	cout << i << endl << endl;

	cout << s << endl;

	setSettings("Yenot", "Inportant", "SoCool");

	system("pause");
    return 0;
}