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

void v_test_1(int i2);
void v_test_1_1(int i2);
void v_test_2_1(int i2);
void v_test_3_1(int i2);
void v_test_10_1();
void v_test();
void v_test_one_bil();
void v_test_one_gaus();
void v_test_one_fast();

int main(int argc, char* argv[]) {
	settings_initialization();

	//char img_source[] = "a.png";
	//Mat img = imread(img_source, 1);
	//imwrite("1.png", img);
	//imwrite("bil.png", mat_bilateral(img_source));
	//imwrite("gaus.png", mat_gaussianblur(img_source));
	//imwrite("fast.png", mat_fastNoiseRemoval(img_source));

	//imwrite("canny.png", mat_canny("fast.png"));
	//v_test_10_1();
	//v_test();

	v_test_one_fast();

	//char name[256], png[256] = ".png";
	//strcat(name, png);
	//cout << name << endl;

	//system("pause");
    return 0;
}

void v_test() {
	for (int i = 1; i <= 64; i++) {
		unsigned int start_time = clock(); // начальное время
		v_test_3_1(i);
		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время
		char ch[1024];
		itoa(search_time, ch, 10);
		logger_xy(search_time, i);
	}
}
void v_test_1(int i2) {
	char img_source[] = "a.png";
	for (int i = 1; i <= i2; i++) {
		char name[256], png[256] = ".png";
		itoa(i, name, 10);
		strcat(name, png);
		imwrite(name, mat_bilateral(img_source));
	}
}
void v_test_1_1(int i2) {
	for (int i = 1; i <= i2; i++) {
		cv::Mat dst = mat_bilateral("a.png");
	}
}
void v_test_2_1(int i2) {
	for (int i = 1; i <= i2; i++) {
		cv::Mat dst = mat_gaussianblur("a.png");
	}
}
void v_test_3_1(int i2) {
	for (int i = 1; i <= i2; i++) {
		cv::Mat dst = mat_fastNoiseRemoval("a.png");
	}
}

void v_test_10_1() {
	cv::Mat dst = mat_bilateral("a.png");
	imwrite("Done.png", dst);
}



void v_test_one_bil() {
	unsigned int start_time = clock(); // начальное время
	
	cv::Mat dst = mat_bilateral("a.png");

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	char ch[1024];
	itoa(search_time, ch, 10);
	logger_xy(search_time, 1);
}

void v_test_one_gaus() {
	unsigned int start_time = clock(); // начальное время

	cv::Mat dst = mat_gaussianblur("a.png");;

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	char ch[1024];
	itoa(search_time, ch, 10);
	logger_xy(search_time, 1);
}

void v_test_one_fast() {
	unsigned int start_time = clock(); // начальное время

	cv::Mat dst = mat_fastNoiseRemoval("a.png");

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	char ch[1024];
	itoa(search_time, ch, 10);
	logger_xy(search_time, 1);
}