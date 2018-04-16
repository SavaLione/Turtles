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

#include "Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	settings_initialization();

	char ch[16];
	getRandom(ch, 15);


	cout << ch << endl;
	getRandom(ch, 15);
	cout << ch << endl;
	getRandom(ch, 15);
	cout << ch << endl;

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