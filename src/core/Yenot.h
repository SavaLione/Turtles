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
	const char settings_file_name[] = "./config.ini"; // FILE_NAME_CONFIG
	
	/// Файл с логами
	const char logger_file_name[] = "Yenot.log"; // FILE_NAME_LOGGER
	
	/// Файл, в котором хранятся 
	const char database_file_name[] = "database.xml"; // FILE_NAME_DATABASE
	
	/// 
	const char database_name[] = "database"; // NAME_DATABASE
	
	/// Расширение для хранения данных
	///
	/// Поддерживается xml и yaml
	const char extensions_database_member[] = ".xml"; // EXTENSIONS_DATABASE_MEMBER
	
	/// Расширение для хранения фотографий
	///
	///Поддерживается png jpg jpeg
	const char extensions_database_member_photo[] = ".png"; // EXTENSIONS_DATABASE_PHOTO
	
	/// Стандартный размер буфера
	const int buffer_size = 128; // BUFFER_SIZE

	///////////////////////////////////////////////////////////////////////////////
	//	Core
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_core[] = "Core"; // BLOCK_CORE
	const char settings_block_default[] = "General"; // BLOCK_DEFAULT

	const char settings_fastmode[] = "fMode"; // SETTINGS_FASTMODE
	const char settings_fastmode_value[] = "0"; // SETTINGS_FASTMODE_VALUE
	const int settings_fastmode_value_int = 0; // SETTINGS_FASTMODE_VALUE_INT

	const char settings_noiseReduction[] = "nReduction"; // SETTINGS_NOISE_REDUCTION
	const char settings_noiseReduction_value[] = "1"; // SETTINGS_NOISE_REDUCTION_VALUE
	const int settings_noiseReduction_value_int = 1; // SETTINGS_NOISE_REDUCTION_VALUE_INT

	const char settings_machineLearning[] = "mLearning"; // SETTINGS_MACHINE_LEARNING
	const char settings_machineLearning_value[] = "1"; // SETTINGS_MACHINE_LEARNING_VALUE
	const int settings_machineLearning_value_int = 1; // SETTINGS_MACHINE_LEARNING_VALUE_INT

	const char settings_lineDetection[] = "lDetection"; // SETTINGS_LINE_DETECTION
	const char settings_lineDetection_value[] = "1"; // SETTINGS_LINE_DETECTION_VALUE
	const int settings_lineDetection_value_int = 1; // SETTINGS_LINE_DETECTION_VALUE_INT

	const char use_detection[] = "detection"; // SETTINGS_DETECTION
	const char use_detection_value[] = "1"; // SETTINGS_DETECTION_VALUE
	const int use_detection_value_int = 1; // SETTINGS_DETECTION_VALUE_INT

	const char save_processed_image[] = "sImage"; // SETTINGS_SAVE_PROCESSED_IMAGE
	const char save_processed_image_value[] = "0"; // SETTINGS_SAVE_PROCESSED_IMAGE_VALUE
	const int save_processed_image_value_int = 0; // SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT
	const char save_processed_image_name[] = "test.png"; // SETTINGS_SAVE_PROCESSED_IMAGE_NAME

	const char settings_log[] = "log"; // SETTINGS_LOG
	const char settings_log_value[] = "1"; // SETTINGS_LOG_VALUE
	const int settings_log_value_int = 1; // SETTINGS_LOG_VALUE_INT
	
	const char settings_logTime[] = "lTime"; // SETTINGS_LOG_TIME
	const char settings_logTime_value[] = "1";// SETTINGS_LOG_TIME
	const int settings_logTime_value_int = 1;
	
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
	const char settings_block_logger[] = "Logger"; // BLOCK_LOGGER

	const char logger_level_warning[] = "WARN"; // LOGGER_LEVEL_WARNING
	const char logger_level_error[] = "ERROR"; // LOGGER_LEVEL_ERROR
	const char logger_level_message[] = "MSG"; // LOGGER_LEVEL_MESSAGE

	///////////////////////////////////////////////////////////////////////////////
	//	Log messages
	///////////////////////////////////////////////////////////////////////////////
	const char logger_message_noiseRemoval[] = "Noise filter is disabled."; // LOGGER_MESSAGE_NOISE_REMOVAL
	const char logger_message_lDetection[] = "Line detection is disabled."; // LOGGER_MESSAGE_LINE_DETECTION
	const char logger_message_fMode[] = "Fast mode enabled."; // LOGGER_MESSAGE_FAST_MODE
	const char logger_message_cDir[] = "Folder created."; // LOGGER_MESSAGE_CREATE_DIR
	const char logger_message_cDir_not[] = "Folder not created."; // LOGGER_MESSAGE_CREATE_DIR_NOT

	///////////////////////////////////////////////////////////////////////////////
	//	Car model
	///////////////////////////////////////////////////////////////////////////////
	const char settings_block_carModel[] = "carmodel"; // BLOCK_CARMODEL
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