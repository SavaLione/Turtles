/**
\file
\brief ќписание
\author SavaLione
*/
#include <Windows.h>
#include <fstream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

#include "Yenot.h"

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////
cv::Mat mat_bilateral(char* ch_image) {

	// Load the source image
	cv::Mat src = cv::imread(ch_image, 1);

	// Create a destination Mat object
	cv::Mat dst;

	/**
	src Ц Source 8-bit or floating-point, 1-channel or 3-channel image.
	dst Ц Destination image of the same size and type as src .
	d Ц Diameter of each pixel neighborhood that is used during filtering. If it is non-positive, it is computed from sigmaSpace.
	sigmaColor Ц Filter sigma in the color space. A larger value of the parameter means that farther colors within the pixel neighborhood (see sigmaSpace ) will be mixed together, resulting in larger areas of semi-equal color.
	sigmaSpace Ц Filter sigma in the coordinate space. A larger value of the parameter means that farther pixels will influence each other as long as their colors are close enough (see sigmaColor ). When d>0 , it specifies the neighborhood size regardless of sigmaSpace . Otherwise, d is proportional to sigmaSpace .
	*/
	bilateralFilter(src, dst, yenot::diameter_each_pixel, yenot::sigmaColor, yenot::sigmaSpace);

	return dst;
}

cv::Mat mat_gaussianblur(char* ch_image) {
	// Load the source image
	cv::Mat src = cv::imread(ch_image, 1);

	// Create a destination Mat object
	cv::Mat dst;

	cv::GaussianBlur(src, dst, cv::Size(yenot::gaussianblur, yenot::gaussianblur), 0, 0);

	return dst;
}

///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////
std::string getSettingsString(char *block, char *value) {
	char text[yenot::buffer_size];
	GetPrivateProfileString(block, value, yenot::ch_default_value, text, yenot::buffer_size, yenot::settings_file_name);
	return text;
}

int getSettings(char *block, char *value) {
	return GetPrivateProfileInt(block, value, yenot::i_return, yenot::settings_file_name);
}

void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}

bool check_file(char *filename) {
	bool b_return = false;
	std::ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

void settings_initialization() {
	if (!check_file((char*)yenot::settings_file_name)) {
		setSettings("General", "initialization", "done");

		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_fastmode, "0");
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_noiseReduction, "1");
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_value_machineLearning, "1");

		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_log, "1");
		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_value_logTime, "1");
	}
}