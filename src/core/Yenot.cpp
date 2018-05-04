/**
	@file
    @brief Описание
	@author SavaLione
	@date 28 Mar 2018
*/
#include "..\core\Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;
using namespace yenot;

void test();

int main(int argc, char* argv[]) {
	bool error = false;
	int i_return = 0;
	Mat src, dst;
	
	char* imagename;
	
	try {
		settingsInitialization();
	} catch (string& e) {
		cerr << e;
		error = true;
		i_return = ERROR_INIT;
	}
	
	//-
	error = true;
	test();
	//-
	
	
	if (!error)
		try {
			if (argc < 2) {
				cerr << ("Usage: " + (string)argv[0] + " image.png");
				throw ("Usage: " + (string)argv[0] + " image.png");
			} else {
				imagename = argv[1];
			}
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_IMAGE;
		}

	if (!error) {
		src = imread(imagename, 1);
	}
	
	if (!error)
		try {
			clearning((NAME_DATABASE + std::string("\\") + FILE_NAME_DATABASE), NAME_DATABASE);
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_CLEARNING;
		}
	
	if (!error)
		try {
			resize(src, dst, Size(settings_size_photo, settings_size_photo));
			if (dst.data) { src = dst.clone(); }
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_RESIZE;
		}
	
	if (!error)
		try {
			noiseRemoval(src, dst);
			if (dst.data) { src = dst.clone(); }
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_NOISE_REMOVAL;
		}

	if (!error)
		try {
			lineDetection(src, dst);
			if (dst.data) { src = dst.clone(); }
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_LINE_DETECTION;
		}

	if (!error)
		try {
			detection(src);
		} catch (string& e) {
			logger((char*)LOGGER_LEVEL_ERROR, (char*)e.c_str());
			error = true;
			i_return = ERROR_DETECTION;
		}

	if (!error)
		if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_SAVE_PROCESSED_IMAGE, SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT)) {
			imwrite((char*)SETTINGS_SAVE_PROCESSED_IMAGE_NAME, src);
		}
	
	return i_return;
}

void test() {
	for (int i = 1; i <= 128; i++) {
		unsigned int start_time = clock();

		///////////////////////////////////////////////////////////////////////////////
		
		cv::Mat image, out;
		image = cv::imread("test.png", 1);
		bilateralFilter(image, out, DIAMETER_EACH_PIXEL, SIGMA_COLOR, SIGMA_SPACE);
		GaussianBlur(image, out, Size(KERNEL_X, KERNEL_Y), 0, 0);
		
		///////////////////////////////////////////////////////////////////////////////

		unsigned int end_time = clock();
		unsigned int search_time = end_time - start_time;

		double d = (double)search_time / 1000.0;

		std::ofstream fout("Gaussian.txt", std::ios_base::app);

		fout << d << " " << i << "\n";
		fout.close();
	}
}