/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <ctime>
#include <filesystem>

#include "Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	settings_initialization();
	buffer_initialization();



	system("pause");
    return 0;
}

/*
for (int i = 0; i <= 4; i++) {
for (int ii = 0; ii <= 16; ii++) {
for (int iii = 0; iii <= 16; iii++) {
char ch = getRandom();
while (ch == getRandom()) {
ch = getRandom();
}
cout << ch;
}
cout << endl;
}
system("pause");
}
*/

/*
WIN32_FIND_DATAW wfd;
HANDLE const hFind = FindFirstFileW(L"./*", &wfd);
if (INVALID_HANDLE_VALUE != hFind)
{
do
{
std::wcout << &wfd.cFileName[0] << std::endl;
} while (NULL != FindNextFileW(hFind, &wfd));

FindClose(hFind);
}
*/