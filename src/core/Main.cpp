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

	CvFileStorage * fs = cvOpenFileStorage("kernel.xml", 0, CV_STORAGE_WRITE);
	cvWriteInt(fs, "name", 128);
	cvReleaseFileStorage(&fs);

	cout << cvReadInt()

	system("pause");
    return 0;
}