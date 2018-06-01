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
	/// Проверяем, нужно ли убирать шум на фотографиях.
	///
	///	Если не нужно убирать шум на фотографиях, то посылаем сообщение в лог
	///
	/// Проверяем режим обработки изображений. Быстрый или нет.
	///
	/// 	Если режим обработки изображений не быстрый, то используем двусторонний фильтр.
	///
	/// иначе
	///
	///		Если режим обработки изображений быстрый, то используем Гауссовый фильтр
	
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_NOISE_REDUCTION, SETTINGS_NOISE_REDUCTION_VALUE_INT)) {
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
	
	Для обычного режима используется - canny(mat_in, mat_out);
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void lineDetection(const Mat& mat_in, Mat& mat_out) {
	/// Проверяем, нужно ли находить линии на изображении.
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_LINE_DETECTION, SETTINGS_LINE_DETECTION_VALUE_INT)) {
		canny(mat_in, mat_out);
	} else {
		logger((char*)LOGGER_LEVEL_WARNING, (char*)LOGGER_MESSAGE_LINE_DETECTION);
	}
}

/**
	@brief Функция для добавления файла с каскадом в файл с информацией о каскадах
	
	@param [in] filename Название каскада с расширением
*/
void databaseAdd(string filename) {
	/// Если название файла не задано, то возвращаем ошибку
	///
	/// Создаём вектор
	///
	/// Создаём файловое хранилище
	///
	/// Открываем файловое хранилище для чтения
	///
	/// Записываем данные из файлового хранилища в вектор
	///
	/// Очищаем файловое хранилище
	/// 
	/// Записываем переменную filename в конец вектора
	///
	/// Создаём файловое хранилище для записи
	///
	/// Записываем в файловое хранилище обработанный вектор
	///
	/// Очищаем файловое хранилище
	
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

/**
	@brief Функция для очистки дубликатов в векторе
	
	@param [in] filename Название и путь к файлу
	@param [in] variable Вектор, в котором нужно удалить дубликаты
*/
void clearning(string filename, string variable) {
	/// Создаём вектор
	///
	/// Создаём файловое хранилище
	///
	/// Открываем файловое хранилище для чтения
	///
	/// Записываем данные из файлового хранилища в вектор
	///
	/// Очищаем файловое хранилище
	///
	/// Сортируем значения вектора
	///
	/// Изменяем размер вектора, удаляя дубликаты
	/// 
	/// Создаём файловое хранилище для записи
	///
	/// Записываем в файловое хранилище обработанный вектор
	///
	/// Очищаем файловое хранилище
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

/**
	@brief Функция для поиска объекта на фото
	
	@param [in] mat_logo Матрица с изображением
	@param [in] cascadefile Файл с каскадом
	@return Результат работы. true - объект найден, false - объект не найден
*/
bool detectionLogo(const Mat& mat_logo, string cascadefile) {
	/// Создаём 2 переменные.
	/// 
	/// 	b_return - возвращаемое значение функции
	///
	/// 		true - объект найден на фото
	///
	/// 		true - объект не найден на фото
	///
	///		image - матрица с изображением
	///
	///	Создаём переменную для хранения каскада logo_cascade
	///
	/// Загружаем каскад (.xml файл)
	///
	/// Если каскад пустой, то возвращаем ошибку
	///
	/// Создаём переменную для распознавания объекта
	///
	///	Загружаем размер шаблона из настроек
	///
	///	Ищем объект на фото
	///
	/// Если объект есть на фото, то возвращаем положительное значение
	
	bool b_return = false;
	Mat image = mat_logo;

	CascadeClassifier logo_cascade;
	logo_cascade.load(NAME_DATABASE + string("\\") + cascadefile);

	if (logo_cascade.empty()) {
		cerr << "Error Loading XML file" << endl;
	}

	vector<Rect> detectObject;
	
	int tSize = getSettings((char*)BLOCK_CORE, (char*)SETTINGS_TEMPLATE_SIZE, TEMPLATE_SIZE);
	logo_cascade.detectMultiScale(image, detectObject, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(tSize, tSize));
	
	if (detectObject.size() != 0) {
		b_return = true;
	}
	return b_return;
}

/**
	@brief Модуль поиска объектов на фото
	
	Поиск объектов на фото
	
	Вывод информации
	
	@param [in] mat_logo Матрица с изображением
*/
void detection(const Mat& mat_logo) {
	/// Проверяем. Нужно ли распознавать объект
	if (getSettings((char*)BLOCK_CORE, (char*)SETTINGS_DETECTION, SETTINGS_DETECTION_VALUE_INT)) {
			/// Создаём вектор
		///
		/// Создаём файловое хранилище
		///
		/// Открываем файловое хранилище для чтения
		///
		/// Записываем данные из файлового хранилища в вектор
		///
		/// Очищаем файловое хранилище
		///
		///	Ищем объект на фото
		///
		/// Если объект есть на фото, то пишем в консоль, что объект найден, иначе пишем, что обхект не найден
		///
		///		[FOUND] [example.xml] description.
		///
		///		[NOT FOUND] [example.xml]
		vector<string> stringVector;
		FileStorage fsIn;
		fsIn.open((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::READ);
		fsIn[NAME_DATABASE] >> stringVector;
		fsIn.release();
		
		for (int i = 0; i <= (stringVector.size() - 1); i++) {
			if (detectionLogo(mat_logo, stringVector[i])) {
				cout << "[FOUND] [" << stringVector[i] << "] " << description(stringVector[i]) << endl;
			} else {
				cout << "[NOT FOUND] " << stringVector[i] << endl;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////

/**
	@brief Модуль настроек.
	
	При отсутствии файла настроек, создаёт его
*/
void settingsInitialization() {
	/// Если папка NAME_DATABASE не найдена и получилось её создать
	///
	///		Вывод в лог, что папка создана
	///
	/// иначе
	///
	///		Вывод в лог информации, что папку не получилось создать (возможно не достаточно прав или она уже создана)
	///
	/// Проверка наличия файла настроек FILE_NAME_CONFIG
	///
	/// Если файла нет, то создать его
	///
	/// 	Добавить в файл параметры
	///
	/// Проверка наличия файла с информацией о каскадах FILE_NAME_DATABASE
	///
	/// Если файла нет, то создать его
	///
	/// Если нет файла CAR_MODEL_EXAMPLE_FILE, то добавить в файл с информацией о каскадах, строку с файлом. Используется для примера
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
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_TEMPLATE_SIZE, (char*)TEMPLATE_SIZE_STR);
		setSettings((char*)BLOCK_CORE, (char*)SETTINGS_SIZE_PHOTO, (char*)SIZE_PHOTO_STR);

		setSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG, (char*)SETTINGS_LOG_VALUE);
		setSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG_TIME, (char*)SETTINGS_LOG_TIME_VALUE);

		setSettings((char*)BLOCK_DESCRIPTION, (char*)CAR_MODEL_EXAMPLE_FILE, (char*)CAR_MODEL_EXAMPLE_DESCRIPTION);

	}
	if (!checkFile(NAME_DATABASE + string("\\") + FILE_NAME_DATABASE)) {
		vector<string> stringVector;
		FileStorage fsOut((NAME_DATABASE + string("\\") + FILE_NAME_DATABASE), FileStorage::WRITE);
		fsOut << NAME_DATABASE << stringVector;
		fsOut.release();
	}
	if (!checkFile(NAME_DATABASE + string("\\") + CAR_MODEL_EXAMPLE_FILE)) {
		databaseAdd(CAR_MODEL_EXAMPLE_FILE);
	}
}

/**
	@brief Функция для поиска описания марки по файлу с каскадом Хаара
	@param [in] value Название файла
	@return Искомое описание марки
*/
string description(string value) {
	/// Создание строковой переменной
	///
	/// Присвоение переменной значения из файла настроек. При отсутствии данных в файле будет присвоено значение DESCRIPTION_NOT_FOUND
	///
	/// Возвращение искомого описания марки
	string s_ret = "";
	s_ret = getSettingsString((char*)BLOCK_DESCRIPTION, (char*)value.c_str(), (char*)DESCRIPTION_NOT_FOUND);
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
	/// Создаём матрицы
	///
	///		gray - матрица с изображением в оттенках серого
	///
	///		edge - матрица с границами
	///
	///	Преобразуем изображение в оттенки серого
	///
	/// Запускаем алгоритм поиска границ
	///
	/// Возвращаем матрицу с обработанным изображением
	Mat gray, edge;
	cvtColor(mat_in, gray, CV_BGR2GRAY);
	Canny(gray, edge, 50, 150, 3);
	edge.convertTo(mat_out, CV_8U);
}
/** @} */