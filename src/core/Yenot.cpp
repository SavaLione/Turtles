/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>

#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <opencv2\opencv.hpp>

#include <ctime>
#include <filesystem>

#include "Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	int i_return = 0;

	settings_initialization();
	clearning((yenot::database_name + std::string("\\") + yenot::database_file_name), yenot::database_name);

	if (argc < 1) {
		help();
		i_return = -1;
	} else {
		Mat src, dst;
		src = imread(argv[1], 1);

		resize(src, dst, Size(128,128));
		src = dst;

		noiseRemoval(src, dst);
		src = dst;

		lineDetection(src, dst);
		src = dst;

		detection(src);
	}


	return i_return;
}

// Yenot.exe image.png cascade.xml