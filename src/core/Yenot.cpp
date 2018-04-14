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

void v_test_1(int i);
void v_test();

int main(int argc, char* argv[]) {
	settings_initialization();

	//char img_source[] = "a.png";
	//Mat img = imread(img_source, 1);
	//imwrite("1.png", img);
	//imwrite("bil.png", mat_bilateral(img_source));
	//imwrite("gaus.png", mat_gaussianblur(img_source));
	//imwrite("fast.png", mat_fastNoiseRemoval(img_source));

	//imwrite("canny.png", mat_canny("fast.png"));

	void v_test();

	//char name[256], png[256] = ".png";
	//strcat(name, png);
	//cout << name << endl;

	//system("pause");
    return 0;
}

void v_test() {
	for (int i = 1; i <= 128; i * 2) {
		unsigned int start_time = clock(); // начальное время
		v_test_1(i);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время
		char ch[1024];
		itoa(search_time, ch, 10);
		logger("TIME", "===================================");
		char cycle[128];
		itoa(i, cycle, 10);
		logger("TIME", cycle);
		logger("TIME", ch);
		logger("TIME", "===================================");
	}
}
void v_test_1(int i) {
	char img_source[] = "a.png";
	for (int i = 1; i <= i; i++) {
		char name[256], png[256] = ".png";
		itoa(i, name, 10);
		//name[1] = i + '0';
		strcat(name, png);
		imwrite(name, mat_bilateral(img_source));
	}
}