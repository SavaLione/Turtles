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

void v_test_3_1(int i2);
void v_test();


int main(int argc, char* argv[]) {
	settings_initialization();

	v_test();

    return 0;
}

void v_test() {
	for (int i = 1; i <= 128; i++) {
		unsigned int start_time = clock(); // начальное время
		v_test_3_1(i);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время

		double d = (double)search_time / 1000.0;

		logger_xy(d, i);
	}
}
void v_test_3_1(int i2) {
	for (int i = 1; i <= i2; i++) {
		cv::Mat dst = mat_blur("a.png");
	}
}