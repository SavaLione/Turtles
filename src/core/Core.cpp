/**
	@file
	@brief Ядро проекта. Содержит все главные и вспомогательные функции для определения марки автомобиля
	@author SavaLione
	@date 12 Apr 2018
*/
#include <Windows.h>
#include <fstream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <cstdlib>
#include <cstdio>
#include <direct.h>
#include <vector>

#include "Yenot.h"
#include "Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;
using namespace yenot;

///////////////////////////////////////////////////////////////////////////////
//	Core
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Функция для обработки изображений.
	
	Проверяет, нужно ли убирать шум на фотографиях.
	
	Также проверяем режим обработки изображений. Быстрый или нет.
	
	Для обычного режима используется двусторонний фильтр - bilateralFilter();
	
	Для быстрого режима используется Гауссовый фильтр размытия изображений - GaussianBlur();
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void noiseRemoval(const Mat& mat_in, Mat& mat_out) {
	if (getSettings((char*)settings_block_core, (char*)settings_noiseReduction, settings_noiseReduction_value_int)) {
		// If no fast
		if (!getSettings((char*)settings_block_core, (char*)settings_fastmode, settings_fastmode_value_int)) {
			bilateralFilter(mat_in, mat_out, diameter_each_pixel, sigmaColor, sigmaSpace);
		} else {
			GaussianBlur(mat_in, mat_out, Size(gaussianblur_kernel_x, gaussianblur_kernel_y), 0, 0);
			logger((char*)logger_level_warning, (char*)logger_message_fMode);
		}
	} else {
		logger((char*)logger_level_warning, (char*)logger_message_noiseRemoval);
	}
}

/**
	@brief Функция для обработки изображений.
	
	Проверяет, нужно ли находить линии на изображении.
	
	Также проверяем режим обработки изображений. Быстрый или нет.
	
	Для обычного режима используется - canny(mat_in, mat_out);
	
	Для быстрого режима используется - 
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void lineDetection(const Mat& mat_in, Mat& mat_out) {
	if (getSettings((char*)settings_block_core, (char*)settings_lineDetection, settings_lineDetection_value_int)) {
		if (!getSettings((char*)settings_block_core, (char*)settings_fastmode, settings_fastmode_value_int)) {
			canny(mat_in, mat_out);
		} else {
			/*===============================================================================================================================================================================*/
			logger((char*)logger_level_warning, (char*)logger_message_fMode);
		}
	} else {
		logger((char*)logger_level_warning, (char*)logger_message_lDetection);
	}
}

void databaseAdd(string filename) {
	vector<string> stringVector;
	FileStorage fsIn;
	fsIn.open((database_name + string("\\") + database_file_name), FileStorage::READ);
	fsIn[database_name] >> stringVector;
	fsIn.release(); //idk

	stringVector.insert(stringVector.end(), filename);

	FileStorage fsOut((database_name + string("\\") + database_file_name), FileStorage::WRITE);
	fsOut << database_name << stringVector;
	fsOut.release();
}

void clearning(string filename, string variable) {
	vector<string> stringVector;
	FileStorage fsIn;
	fsIn.open(filename, FileStorage::READ);
	fsIn[variable] >> stringVector;
	fsIn.release(); //idk

	sort(stringVector.begin(), stringVector.end());
	stringVector.resize(unique(stringVector.begin(), stringVector.end()) - stringVector.begin());

	FileStorage fsOut(filename, FileStorage::WRITE);
	fsOut << variable << stringVector;
	fsOut.release();
}

bool detectionLogo(const Mat& mat_logo, string cascadefile) {
	bool b_return = false;
	Mat image = mat_logo;

	// Load cascade (.xml file)
	CascadeClassifier logo_cascade;
	logo_cascade.load(cascadefile);

	if (logo_cascade.empty()) {
		cerr << "Error Loading XML file" << endl;
	}

	// Detect object
	vector<Rect> detectObject;
	logo_cascade.detectMultiScale(image, detectObject, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(settings_size_photo, settings_size_photo));

	if (detectObject.size() != 0) {
		// ≈сть на фото
		cout << detectObject.size() << endl;
		b_return = true;
	}
	return b_return;
}

void help() {
	cout << " Usage: Yenot.exe <image>" << endl;
}

void detection(const Mat& mat_logo) {
	if (getSettings((char*)settings_block_core, (char*)use_detection, use_detection_value_int)) {
		vector<string> stringVector;
		FileStorage fsIn;
		fsIn.open((database_name + string("\\") + database_file_name), FileStorage::READ);
		fsIn[database_name] >> stringVector;
		fsIn.release();

		vector<bool> boolVector;

		for (int i = 0; i <= (stringVector.size() - 1); i++) {
			if (detectionLogo(mat_logo, stringVector[i])) {
				boolVector[i] = true;
			}
		}

		for (int i = 0; i <= (stringVector.size() - 1); i++) {
			if (boolVector[i]) {
				cout << description(stringVector[i]) << endl;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////

/**
	@brief Функция для обработки изображений.
	
	Фильтр для размытия изображений.
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void blur(const Mat& mat_in, Mat& mat_out) {
	blur(mat_in, mat_out, Size(blur_kernel_x, blur_kernel_y));
}

/**
	@brief Функция для обработки изображений.
	
	Быстрый фильтр для размытия изображений в оттенках серого.
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void fastNoiseRemovalGrey(const Mat& mat_in, Mat& mat_out) {
	fastNlMeansDenoising(mat_in, mat_out, 3.0f, 7, 21);
}

/**
	@brief Функция для обработки изображений.
	
	Быстрый фильтр для размытия изображений в оттенках серого.
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void fastNoiseRemoval(const Mat& mat_in, Mat& mat_out) {
	fastNlMeansDenoising(mat_in, mat_out, 3.0f, 7, 21);
}

///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////
string getSettingsString(char *block, char *value) {
	char text[buffer_size];
	GetPrivateProfileString(block, value, settings_block_default, text, buffer_size, settings_file_name);
	return text;
}

string getSettingsString(char *block, char *value, char *ch_return_default) {
	char text[buffer_size];
	GetPrivateProfileString(block, value, ch_return_default, text, buffer_size, settings_file_name);
	return text;
}

int getSettings(char *block, char *value) {
	return GetPrivateProfileInt(block, value, -1, settings_file_name);
}

int getSettings(char *block, char *value, int i_return_default) {
	return GetPrivateProfileInt(block, value, i_return_default, settings_file_name);
}

void setSettings(char *block, char *value, char *text) {
	WritePrivateProfileString(block, value, text, settings_file_name);
}

bool check_file(char *filename) {
	bool b_return = false;
	ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}
bool check_file(string filename) {
	bool b_return = false;
	ifstream file;
	file.open(filename);
	if (file) {
		b_return = true;
	}
	return b_return;
}

void settings_initialization() {
	if ((_mkdir((char*)database_name)) == 0) {
		logger((char*)logger_level_warning, (char*)logger_message_cDir);
	} else {
		logger((char*)logger_level_warning, (char*)logger_message_cDir_not);
	}
	if (!check_file((char*)settings_file_name)) {
		createFile((char*)settings_file_name);

		setSettings((char*)settings_block_core, (char*)settings_fastmode, (char*)settings_fastmode_value);
		setSettings((char*)settings_block_core, (char*)settings_noiseReduction, (char*)settings_noiseReduction_value);
		setSettings((char*)settings_block_core, (char*)settings_machineLearning, (char*)settings_machineLearning_value);
		setSettings((char*)settings_block_core, (char*)use_detection, (char*)use_detection_value);
		setSettings((char*)settings_block_core, (char*)save_processed_image, (char*)save_processed_image_value);

		setSettings((char*)settings_block_logger, (char*)settings_log, (char*)settings_log_value);
		setSettings((char*)settings_block_logger, (char*)settings_logTime, (char*)settings_logTime_value);

		setSettings((char*)settings_block_carModel, (char*)settings_carModel_example, (char*)settings_carModel_example_description);

		setSettings((char*)settings_block_description, (char*)settings_carModel_example_file, (char*)settings_description_example);

	}
	if (!check_file(database_name + string("\\") + database_file_name)) {
		vector<string> stringVector;
		FileStorage fsOut((database_name + string("\\") + database_file_name), FileStorage::WRITE);
		fsOut << database_name << stringVector;
		fsOut.release();
	}
	if (!check_file(database_name + string("\\") + settings_carModel_example_file)) {
		databaseAdd(settings_carModel_example_file);
	}
}

/**
	@brief Функция для создания файла
	@param [in] file_name Путь и название файла
*/
void createFile(char *file_name) {
	ofstream fout(file_name);
	fout.close();
}

/**
	@brief Функция для создания директории
	@param [in] namedir Путь и название директории
*/
void createDir(string namedir) {
	///	Если успешно создали директорию, то:
	///
	///		Вывод в лог, что получилось создать директорию
	///
	/// иначе:
	///
	///		Вывод в лог, что не получилось создать директорию
	///
	///		Возможно это связано с тем, что нет прав на создание директории или директория уже есть
	if ((_mkdir(namedir.c_str())) == 0) {
		logger((char*)logger_level_warning, (char*)logger_message_cDir);
	} else {
		logger((char*)logger_level_warning, (char*)logger_message_cDir_not);
	}
}

/**
	@brief Функция для поиска описания марки по файлу с каскадом Хаара
	@param [in] value Название файла
	@return Искомое описание марки
*/
string description(string value) {
	string s_ret = "";
	s_ret = getSettingsString((char*)settings_block_description, (char*)value.c_str(), (char*)settings_description_ifnotfound);
	return s_ret;
}

///////////////////////////////////////////////////////////////////////////////
//	Line detector
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Функция для обработки изображений.
	
	Поиск границ на изображении. Метод canny.
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void canny(const Mat& mat_in, Mat& mat_out) {
	Mat gray, edge, draw;
	cvtColor(mat_in, gray, CV_BGR2GRAY);
	Canny(gray, edge, 50, 150, 3);
	edge.convertTo(mat_out, CV_8U);
}

///////////////////////////////////////////////////////////////////////////////
//	Test
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Функция для проведения тестов. Замер скорости выполнения алгоритмов.
*/
void v_test() {
	for (int i = 1; i <= 128; i++) {
		unsigned int start_time = clock(); // начальное время

		///////////////////////////////////////////////////////////////////////////////
		Mat image, out;
		image = imread("a.png", 1);
		canny(image, out);
		///////////////////////////////////////////////////////////////////////////////

		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время

		double d = (double)search_time / 1000.0;

		logger_xy(d, i);
	}
}