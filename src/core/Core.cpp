/**
	@file
	@brief Ядро проекта. Содержит все главные и вспомогательные функции для определения марки автомобиля
	@author SavaLione
	@date 12 Apr 2018
*/
/**
	@defgroup corecpp Core.cpp
	@ingroup core
	@{
*/
#include <Windows.h>
#include <direct.h>

#include "..\core\Yenot.h"
#include "..\core\Core.h"
#include "..\core\Logger.h"
#include "..\core\Settings.h"

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
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_NOISE_REDUCTION, SETTINGS_NOISE_REDUCTION_VALUE_INT)) {
		// If no fast
		if (!getSettings((char*)BLOCK_CORE, (char*)SETTINGS_FASTMODE, SETTINGS_FASTMODE_VALUE_INT)) {
			bilateralFilter(mat_in, mat_out, DIAMETER_EACH_PIXEL, SIGMA_COLOR, SIGMA_SPACE);
		} else {
			GaussianBlur(mat_in, mat_out, Size(KERNEL_X, KERNEL_Y), 0, 0);
			logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_FAST_MODE);
		}
	} else {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_NOISE_REMOVAL);
	}
}

/**
	@brief Функция для обработки изображений.
	
	Проверяет, нужно ли находить линии на изображении.
	
	Также проверяем режим обработки изображений. Быстрый или нет.
	
	Для обычного режима используется - canny(mat_in, mat_out);
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void lineDetection(const Mat& mat_in, Mat& mat_out) {
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_LINE_DETECTION, SETTINGS_LINE_DETECTION_VALUE_INT)) {
		canny(mat_in, mat_out);
	} else {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_LINE_DETECTION);
	}
}

void databaseAdd(string filename) {
	if (filename == "")
		throw ERROR_INIT_DATABASE_ADD;
	vector<string> stringVector;
	FileStorage fsIn;
	fsIn.open((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::READ);
	fsIn[NAME_DATABASE] >> stringVector;
	fsIn.release();

	stringVector.insert(stringVector.end(), filename);

	FileStorage fsOut((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::WRITE);
	fsOut << NAME_DATABASE << stringVector;
	fsOut.release();
}

void clearning(string filename, string variable) {
	vector<string> stringVector;
	FileStorage fsIn;
	fsIn.open(filename, FileStorage::READ);
	fsIn[variable] >> stringVector;
	fsIn.release(); 

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
	logo_cascade.detectMultiScale(image, detectObject, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(TEMPLATE_SIZE, TEMPLATE_SIZE));
	
	cout << "[START]" << endl;
	if (detectObject.size() != 0) {
		cout << "[FOUND]" << endl;
		// Вывод описания
		cout << detectObject.size() << endl;
		cout << getSettingsString((char*)settings_block_description, (char*)cascadefile.c_str(), (char*)settings_description_name_not_set) << endl;
		// Есть на фото
		cout << detectObject.size() << endl;
		b_return = true;
	}
	cout << "[END]" << endl;
	return b_return;
}

void detection(const Mat& mat_logo) {
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_DETECTION, SETTINGS_DETECTION_VALUE_INT)) {
		vector<string> stringVector;
		FileStorage fsIn;
		fsIn.open((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::READ);
		fsIn[NAME_DATABASE] >> stringVector;
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
//	Settings
///////////////////////////////////////////////////////////////////////////////

void settingsInitialization() {
	if ((_mkdir((char*)NAME_DATABASE)) == 0) {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_CREATE_DIR);
	} else {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_CREATE_DIR_NOT);
	}
	if (!checkFile((char*)FILE_NAME_CONFIG)) {
		createFile((char*)FILE_NAME_CONFIG);

		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_FASTMODE, (char*)SETTINGS_FASTMODE_VALUE);
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_NOISE_REDUCTION, (char*)SETTINGS_NOISE_REDUCTION_VALUE);
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_LINE_DETECTION, (char*)SETTINGS_LINE_DETECTION_VALUE);
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_DETECTION, (char*)SETTINGS_DETECTION_VALUE);
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_SAVE_PROCESSED_IMAGE, (char*)SETTINGS_SAVE_PROCESSED_IMAGE_VALUE);

		setSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG, (char*)SETTINGS_LOG_VALUE);
		setSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG_TIME, (char*)SETTINGS_LOG_TIME_VALUE);

		setSettings((char*)BLOCK_CARMODEL, (char*)settings_carModel_example, (char*)settings_carModel_example_description);

		setSettings((char*)settings_block_description, (char*)settings_carModel_example_file, (char*)settings_description_example);

	}
	if (!checkFile(NAME_DATABASE + string("\\") + FILE_NAME_DATABASE)) {
		vector<string> stringVector;
		FileStorage fsOut((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::WRITE);
		fsOut << NAME_DATABASE << stringVector;
		fsOut.release();
	}
	if (!checkFile(NAME_DATABASE + string("\\") + settings_carModel_example_file)) {
		databaseAdd(settings_carModel_example_file);
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
/** @} */