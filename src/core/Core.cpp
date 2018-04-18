/**
\file
\brief ��������
\author SavaLione
*/
#include <Windows.h>
#include <fstream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <cstdlib>
#include <cstdio>
#include <direct.h>

#include "Yenot.h"
#include "Core.h"
#include "..\io\Logger.h"

///////////////////////////////////////////////////////////////////////////////
//	Core
///////////////////////////////////////////////////////////////////////////////

cv::Mat noiseRemoval(char* source) {
	cv::Mat dst = yenot::mat_return;
	if (getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_noiseReduction, yenot::settings_noiseReduction_value_int)) {
		// If no fast
		if (!getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_fastmode, yenot::settings_fastmode_value_int)) {
			dst = mat_bilateral(source);
		} else {
			dst = mat_gaussianblur(source);
			logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_fMode);
		}
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_noiseRemoval);
	}
	return dst;
}

cv::Mat lineDetection(char* source) {
	cv::Mat dst = yenot::mat_return;
	if (getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_lineDetection, yenot::settings_lineDetection_value_int)) {
		if (!getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_fastmode, yenot::settings_fastmode_value_int)) {
			dst = mat_canny(source);
		} else {
			/*===============================================================================================================================================================================*/
			logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_fMode);
		}
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_lDetection);
	}
	return dst;
}

void noiseRemoval(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::Mat dst = yenot::mat_return;
	if (getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_noiseReduction, yenot::settings_noiseReduction_value_int)) {
		// If no fast
		if (!getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_fastmode, yenot::settings_fastmode_value_int)) {
			bilateral(mat_in, mat_out);
		} else {
			gaussianblur(mat_in, mat_out);
			logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_fMode);
		}
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_noiseRemoval);
	}
}

void lineDetection(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::Mat dst = yenot::mat_return;
	if (getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_lineDetection, yenot::settings_lineDetection_value_int)) {
		if (!getSettings((char*)yenot::settings_block_core, (char*)yenot::settings_fastmode, yenot::settings_fastmode_value_int)) {
			canny(mat_in, mat_out);
		} else {
			/*===============================================================================================================================================================================*/
			logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_fMode);
		}
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::logger_message_lDetection);
	}
}

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////
/* OLD */
cv::Mat mat_bilateral(char* source) {
	cv::Mat src = cv::imread(source, 1);
	cv::Mat dst;

	/**
	src � Source 8-bit or floating-point, 1-channel or 3-channel image.
	dst � Destination image of the same size and type as src .
	d � Diameter of each pixel neighborhood that is used during filtering. If it is non-positive, it is computed from sigmaSpace.
	sigmaColor � Filter sigma in the color space. A larger value of the parameter means that farther colors within the pixel neighborhood (see sigmaSpace ) will be mixed together, resulting in larger areas of semi-equal color.
	sigmaSpace � Filter sigma in the coordinate space. A larger value of the parameter means that farther pixels will influence each other as long as their colors are close enough (see sigmaColor ). When d>0 , it specifies the neighborhood size regardless of sigmaSpace . Otherwise, d is proportional to sigmaSpace .
	*/
	bilateralFilter(src, dst, yenot::diameter_each_pixel, yenot::sigmaColor, yenot::sigmaSpace);

	return dst;
}

/* OLD */
cv::Mat mat_gaussianblur(char* source) {
	// Load the source image
	cv::Mat src = cv::imread(source, 1);

	// Create a destination Mat object
	cv::Mat dst;

	cv::GaussianBlur(src, dst, cv::Size(yenot::gaussianblur_kernel_x, yenot::gaussianblur_kernel_y), 0, 0);

	return dst;
}

/* OLD */
cv::Mat mat_fastNoiseRemoval(char* source) {
	cv::Mat dst = cv::imread(source, 1);
	cv::fastNlMeansDenoising(dst, dst, 3.0f, 7, 21);
	return dst;
}

/* OLD */
cv::Mat mat_fastNoiseRemovalGrey(char* source) {
	cv::Mat dst = cv::imread(source, 0);
	cv::fastNlMeansDenoising(dst, dst, 3.0f, 7, 21);
	return dst;
}

/* OLD */
cv::Mat mat_blur(char* source) {
	cv::Mat dst = cv::imread(source, 1);
	cv::blur(dst, dst, cv::Size(yenot::blur_kernel_x, yenot::blur_kernel_y));
	return dst;
}

void bilateral(const cv::Mat& mat_in, cv::Mat& mat_out) {
	//mat_out = mat_in.clone();

	/**
	src � Source 8-bit or floating-point, 1-channel or 3-channel image.
	dst � Destination image of the same size and type as src .
	d � Diameter of each pixel neighborhood that is used during filtering. If it is non-positive, it is computed from sigmaSpace.
	sigmaColor � Filter sigma in the color space. A larger value of the parameter means that farther colors within the pixel neighborhood (see sigmaSpace ) will be mixed together, resulting in larger areas of semi-equal color.
	sigmaSpace � Filter sigma in the coordinate space. A larger value of the parameter means that farther pixels will influence each other as long as their colors are close enough (see sigmaColor ). When d>0 , it specifies the neighborhood size regardless of sigmaSpace . Otherwise, d is proportional to sigmaSpace .
	*/
	bilateralFilter(mat_in, mat_out, yenot::diameter_each_pixel, yenot::sigmaColor, yenot::sigmaSpace);
}

void blur(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::blur(mat_in, mat_out, cv::Size(yenot::blur_kernel_x, yenot::blur_kernel_y));
}

void fastNoiseRemovalGrey(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::fastNlMeansDenoising(mat_in, mat_out, 3.0f, 7, 21);
}

void gaussianblur(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::GaussianBlur(mat_in, mat_out, cv::Size(yenot::gaussianblur_kernel_x, yenot::gaussianblur_kernel_y), 0, 0);
}

void fastNoiseRemoval(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::fastNlMeansDenoising(mat_in, mat_out, 3.0f, 7, 21);
}
///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////
std::string getSettingsString(char *block, char *value) {
	char text[yenot::buffer_size];
	GetPrivateProfileString(block, value, yenot::settings_block_default, text, yenot::buffer_size, yenot::settings_file_name);
	return text;
}

std::string getSettingsString(char *block, char *value, char *ch_return_default) {
	char text[yenot::buffer_size];
	GetPrivateProfileString(block, value, ch_return_default, text, yenot::buffer_size, yenot::settings_file_name);
	return text;
}

int getSettings(char *block, char *value) {
	return GetPrivateProfileInt(block, value, yenot::i_return, yenot::settings_file_name);
}

int getSettings(char *block, char *value, int i_return_default) {
	return GetPrivateProfileInt(block, value, i_return_default, yenot::settings_file_name);
}

void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, yenot::settings_file_name);
}

bool check_file(char *filename) {
	bool b_return = yenot::b_return;
	std::ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

bool check_file(char *filename, bool b_return_default) {
	bool b_return = b_return_default;
	std::ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

void settings_initialization() {
	if (!check_file((char*)yenot::settings_file_name)) {
		createFile((char*)yenot::settings_file_name);
		
		setSettings("General", "initialization", "done");

		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_fastmode, (char*)yenot::settings_fastmode_value);
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_noiseReduction, (char*)yenot::settings_noiseReduction_value);
		setSettings((char*)yenot::settings_block_core, (char*)yenot::settings_machineLearning, (char*)yenot::settings_machineLearning_value);

		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_log, (char*)yenot::settings_log_value);
		setSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_logTime, (char*)yenot::settings_logTime_value);

	}
}

void buffer_initialization() {
	if (_mkdir((char*)yenot::buffer_dir_name) == 0) {
		logger((char*)yenot::logger_level_error, (char*)yenot::buffer_dir_not_found);
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::buffer_dir_found);
	}
	if (check_file((char*)yenot::buffer_file_name_img)) {
		if (remove((char*)yenot::buffer_file_name_img) == 0) {
			logger((char*)yenot::logger_level_warning, (char*)yenot::buffer_img_found);
		} else {
			logger((char*)yenot::logger_level_error, (char*)yenot::buffer_img_found_err);
		}
	} else {
		logger((char*)yenot::logger_level_warning, (char*)yenot::buffer_img_not_found);
	}
}


void createFile(char *file_name) {
	std::ofstream fout(file_name);
	fout.close();
}

///////////////////////////////////////////////////////////////////////////////
//	Line detector
///////////////////////////////////////////////////////////////////////////////
/* OLD */
cv::Mat mat_canny(char* ch_image) {
	cv::Mat src1 = cv::imread(ch_image, CV_LOAD_IMAGE_COLOR);
	cv::Mat gray, edge, draw;
	cvtColor(src1, gray, CV_BGR2GRAY);
	Canny(gray, edge, 50, 150, 3);
	edge.convertTo(draw, CV_8U);
	return draw;
}

void canny(const cv::Mat& mat_in, cv::Mat& mat_out) {
	cv::Mat gray, edge, draw;
	cvtColor(mat_in, gray, CV_BGR2GRAY);
	Canny(gray, edge, 50, 150, 3);
	edge.convertTo(mat_out, CV_8U);
}

///////////////////////////////////////////////////////////////////////////////
//	Test
///////////////////////////////////////////////////////////////////////////////

void v_test() {
	for (int i = 1; i <= 128; i++) {
		unsigned int start_time = clock(); // ��������� �����

		cv::Mat dst = mat_canny("a.png");

		unsigned int end_time = clock(); // �������� �����
		unsigned int search_time = end_time - start_time; // ������� �����

		double d = (double)search_time / 1000.0;

		logger_xy(d, i);
	}
}