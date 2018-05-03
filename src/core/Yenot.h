/**
	@file
	@brief Заголовочный файл с пространством имён, которое хранит в себе константы.
	@author SavaLione
	@date 3 Apr 2018
*/
#ifndef YENOT_H
#define YENOT_H

#include <opencv2/opencv.hpp>

/**
	@brief Пространство имён с константами
	
	General - Основные константы
	
	Core - Ядро
	
	Filters - Фильтры
	
	Logger - Модуль логирования
	
	Log messages - Сообщения для вывода в логами
	
	Car model - Пример
*/
namespace yenot {
	///////////////////////////////////////////////////////////////////////////////
	//	General
	///////////////////////////////////////////////////////////////////////////////
	
	/// Файл с настройками
	const char FILE_NAME_CONFIG[] = "./config.ini"; // FILE_NAME_CONFIG
	
	/// Файл с логами
	const char FILE_NAME_LOGGER[] = "Yenot.log"; // FILE_NAME_LOGGER
	
	/// Файл, в котором хранятся 
	const char FILE_NAME_DATABASE[] = "database.xml"; // FILE_NAME_DATABASE
	
	/// 
	const char NAME_DATABASE[] = "database"; // NAME_DATABASE
	
	/// Расширение для хранения данных
	///
	/// Поддерживается xml и yaml
	const char EXTENSIONS_DATABASE_MEMBER[] = ".xml"; // EXTENSIONS_DATABASE_MEMBER
	
	/// Расширение для хранения фотографий
	///
	///Поддерживается png jpg jpeg
	const char EXTENSIONS_DATABASE_MEMBER_photo[] = ".png"; // EXTENSIONS_DATABASE_PHOTO
	
	/// Стандартный размер буфера
	const int BUFFER_SIZE = 128; // BUFFER_SIZE

	///////////////////////////////////////////////////////////////////////////////
	//	Core
	///////////////////////////////////////////////////////////////////////////////
	const char BLOCK_CORE[] = "Core"; // BLOCK_CORE
	const char BLOCK_DEFAULT[] = "General"; // BLOCK_DEFAULT

	const char SETTINGS_FASTMODE[] = "fMode"; // SETTINGS_FASTMODE
	const char SETTINGS_FASTMODE_VALUE[] = "0"; // SETTINGS_FASTMODE_VALUE
	const int SETTINGS_FASTMODE_VALUE_INT = 0; // SETTINGS_FASTMODE_VALUE_INT

	const char SETTINGS_NOISE_REDUCTION[] = "nReduction"; // SETTINGS_NOISE_REDUCTION
	const char SETTINGS_NOISE_REDUCTION_VALUE[] = "1"; // SETTINGS_NOISE_REDUCTION_VALUE
	const int SETTINGS_NOISE_REDUCTION_VALUE_INT = 1; // SETTINGS_NOISE_REDUCTION_VALUE_INT

	const char SETTINGS_MACHINE_LEARNING[] = "mLearning"; // SETTINGS_MACHINE_LEARNING
	const char SETTINGS_MACHINE_LEARNING_VALUE[] = "1"; // SETTINGS_MACHINE_LEARNING_VALUE
	const int SETTINGS_MACHINE_LEARNING_VALUE_INT = 1; // SETTINGS_MACHINE_LEARNING_VALUE_INT

	const char SETTINGS_LINE_DETECTION[] = "lDetection"; // SETTINGS_LINE_DETECTION
	const char SETTINGS_LINE_DETECTION_VALUE[] = "1"; // SETTINGS_LINE_DETECTION_VALUE
	const int SETTINGS_LINE_DETECTION_VALUE_INT = 1; // SETTINGS_LINE_DETECTION_VALUE_INT

	const char SETTINGS_DETECTION[] = "detection"; // SETTINGS_DETECTION
	const char SETTINGS_DETECTION_VALUE[] = "1"; // SETTINGS_DETECTION_VALUE
	const int SETTINGS_DETECTION_VALUE_INT = 1; // SETTINGS_DETECTION_VALUE_INT

	const char SETTINGS_SAVE_PROCESSED_IMAGE[] = "sImage"; // SETTINGS_SAVE_PROCESSED_IMAGE
	const char SETTINGS_SAVE_PROCESSED_IMAGE_VALUE[] = "0"; // SETTINGS_SAVE_PROCESSED_IMAGE_VALUE
	const int SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT = 0; // SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT
	const char SETTINGS_SAVE_PROCESSED_IMAGE_NAME[] = "test.png"; // SETTINGS_SAVE_PROCESSED_IMAGE_NAME

	const char SETTINGS_LOG[] = "log"; // SETTINGS_LOG
	const char SETTINGS_LOG_VALUE[] = "1"; // SETTINGS_LOG_VALUE
	const int SETTINGS_LOG_VALUE_INT = 1; // SETTINGS_LOG_VALUE_INT
	
	const char SETTINGS_LOG_TIME[] = "lTime"; // SETTINGS_LOG_TIME
	const char SETTINGS_LOG_TIME_VALUE[] = "1"; // SETTINGS_LOG_TIME_VALUE
	const int SETTINGS_LOG_TIME_VALUE_INT = 1; // SETTINGS_LOG_TIME_VALUE_INT
	
	///////////////////////////////////////////////////////////////////////////////
	//	Filters
	///////////////////////////////////////////////////////////////////////////////
	const int diameter_each_pixel = 9;
	const int sigmaColor = 75;
	const int sigmaSpace = 75;
	
	/// Фильтр Гаусса. Размер ядра по x
	///
	/// Число не чётное
	const int gaussianblur_kernel_x = 5; // KERNEL_X
	
	/// Фильтр Гаусса. Размер ядра по x
	///
	/// Число не чётное
	const int gaussianblur_kernel_y = 5; // KERNEL_Y
	
	/// Размытие. Размер ядра по x
	///
	/// Число не чётное
	const int blur_kernel_x = 5;
	
	/// Размытие. Размер ядра по x
	///
	/// Число не чётное
	const int blur_kernel_y = 5;

	///////////////////////////////////////////////////////////////////////////////
	//	Logger
	///////////////////////////////////////////////////////////////////////////////
	const char BLOCK_LOGGER[] = "Logger"; // BLOCK_LOGGER

	const char LOGGER_LEVEL_WARNING[] = "WARN"; // LOGGER_LEVEL_WARNING
	const char LOGGER_LEVEL_ERROR[] = "ERROR"; // LOGGER_LEVEL_ERROR
	const char LOGGER_LEVEL_MESSAGE[] = "MSG"; // LOGGER_LEVEL_MESSAGE

	///////////////////////////////////////////////////////////////////////////////
	//	Log messages
	///////////////////////////////////////////////////////////////////////////////
	const char LOGGER_MESSAGE_NOISE_REMOVAL[] = "Noise filter is disabled."; // LOGGER_MESSAGE_NOISE_REMOVAL
	const char LOGGER_MESSAGE_LINE_DETECTION[] = "Line detection is disabled."; // LOGGER_MESSAGE_LINE_DETECTION
	const char LOGGER_MESSAGE_FAST_MODE[] = "Fast mode enabled."; // LOGGER_MESSAGE_FAST_MODE
	const char LOGGER_MESSAGE_CREATE_DIR[] = "Folder created."; // LOGGER_MESSAGE_CREATE_DIR
	const char LOGGER_MESSAGE_CREATE_DIR_NOT[] = "Folder not created."; // LOGGER_MESSAGE_CREATE_DIR_NOT

	///////////////////////////////////////////////////////////////////////////////
	//	Car model
	///////////////////////////////////////////////////////////////////////////////
	const char BLOCK_CARMODEL[] = "carmodel"; // BLOCK_CARMODEL
	const char settings_carModel_listphoto[] = "listphoto";

	const char settings_carModel_example[] = "example";
	const char settings_carModel_example_description[] = "The car of model \"Example\"";
	const char settings_carModel_example_file[] = "example.xml";

	const char settings_block_description[] = "description";
	const char settings_description_ifnotfound[] = "Not found";
	const char settings_description_example[] = "Example brand";

	const int settings_size_photo = 512;
}

#endif // YENOT_H