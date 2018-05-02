/**
	@file
    @brief Описание
	@author SavaLione
	@date 28 Mar 2018
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
using namespace yenot;

int main(int argc, char* argv[]) {
	int i_return = 0;
	Mat src, dst;
	char* imagename = argc == 2 ? argv[1] : "image.png";

	src = imread(imagename, 1);

	settings_initialization();
	clearning((database_name + std::string("\\") + database_file_name), database_name);


	resize(src, dst, Size(settings_size_photo, settings_size_photo));
	if (dst.data) { src = dst.clone(); }

	noiseRemoval(src, dst);
	if (dst.data) { src = dst.clone(); }

	lineDetection(src, dst);
	if (dst.data) { src = dst.clone(); }

	detection(src);

	if (getSettings((char*)settings_block_core, (char*)save_processed_image, save_processed_image_value_int)) {
		imwrite((char*)save_processed_image_name, src);
	}

	system("pause");
	return i_return;
}