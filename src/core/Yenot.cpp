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

int main(int argc, char* argv[]) {
	int i_return = 0;
	Mat src, dst;
	char* imagename = argc == 2 ? argv[1] : "image.png";

	src = imread(imagename, 1);

	settings_initialization();
	clearning((yenot::database_name + std::string("\\") + yenot::database_file_name), yenot::database_name);


	resize(src, dst, Size(yenot::settings_size_photo, yenot::settings_size_photo));
	if (dst.data) { src = dst.clone(); }

	noiseRemoval(src, dst);
	if (dst.data) { src = dst.clone(); }

	lineDetection(src, dst);
	if (dst.data) { src = dst.clone(); }

	detection(src);

	if (getSettings((char*)yenot::settings_block_core, (char*)yenot::save_processed_image, yenot::save_processed_image_value_int)) {
		imwrite((char*)yenot::save_processed_image_name, src);
	}

	system("pause");
	return i_return;
}