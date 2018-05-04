/**
	@file
	@brief Заголовочный файл с пространством имён, которое хранит в себе константы.
	@author SavaLione
	@date 3 Apr 2018
*/
/**
	@defgroup yenot Yenot
	@brief Общие файлы
*/
/**
	@defgroup core Core
	@brief Работа с изображениеми, xml(yaml) файлами
*/
/**
	@defgroup server Сервер
	@brief Сервер. Должен принимать фото
*/
/**
	@defgroup yenoth Yenot.h
	@ingroup yenot
	@{
*/
#ifndef YENOT_H
#define YENOT_H

/**
	@brief Пространство имён с константами
	
	General - Основные константы
	
	Core - Ядро
	
	Filters - Фильтры
	
	Logger - Модуль логирования
	
	Log messages - Сообщения для вывода в логами
	
	Errors - Ошибки
	
	Car model - Пример
*/
namespace yenot {
	///////////////////////////////////////////////////////////////////////////////
	//	General
	///////////////////////////////////////////////////////////////////////////////
	
	/// Файл с настройками
	const char FILE_NAME_CONFIG[] = "./config.ini";
	
	/// Файл с логами
	const char FILE_NAME_LOGGER[] = "Yenot.log";
	
	/// Файл, в котором хранятся 
	const char FILE_NAME_DATABASE[] = "database.xml";
	
	/// 
	const char NAME_DATABASE[] = "database";
	
	/// Расширение для хранения данных
	///
	/// Поддерживается xml и yaml
	const char EXTENSIONS_DATABASE_MEMBER[] = ".xml";
	
	/// Расширение для хранения фотографий
	///
	///Поддерживается png jpg jpeg
	const char EXTENSIONS_DATABASE_MEMBER_photo[] = ".png";
	
	/// Стандартный размер буфера
	const int BUFFER_SIZE = 128;

	///////////////////////////////////////////////////////////////////////////////
	//	Core
	///////////////////////////////////////////////////////////////////////////////
	
	/// Блок настроек ядра.
	///
	///	ini файл
	/// @code
	///	[core]
	/// ...
	/// @endcode
	const char BLOCK_CORE[] = "Core";
	
	/// Быстрый режим.
	///
	/// Немного ускоряет работу программы
	const char SETTINGS_FASTMODE[] = "fMode";
	/// Быстрый режим.
	///
	/// Стандартное значение
	const char SETTINGS_FASTMODE_VALUE[] = "0";
	/// Быстрый режим.
	///
	/// Стандартное значение
	const int SETTINGS_FASTMODE_VALUE_INT = 0;

	/// Алгоритм очистки изображения от шума.
	///
	/// Замедляет работу программы
	const char SETTINGS_NOISE_REDUCTION[] = "nReduction";
	/// Алгоритм очистки изображения от шума.
	///
	/// Стандартное значение
	const char SETTINGS_NOISE_REDUCTION_VALUE[] = "1";
	/// Алгоритм очистки изображения от шума.
	///
	/// Стандартное значение
	const int SETTINGS_NOISE_REDUCTION_VALUE_INT = 1;

	const char SETTINGS_LINE_DETECTION[] = "lDetection";
	const char SETTINGS_LINE_DETECTION_VALUE[] = "1";
	const int SETTINGS_LINE_DETECTION_VALUE_INT = 1;

	const char SETTINGS_DETECTION[] = "detection";
	const char SETTINGS_DETECTION_VALUE[] = "1";
	const int SETTINGS_DETECTION_VALUE_INT = 1;

	const char SETTINGS_SAVE_PROCESSED_IMAGE[] = "sImage";
	const char SETTINGS_SAVE_PROCESSED_IMAGE_VALUE[] = "0";
	const int SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT = 0;
	const char SETTINGS_SAVE_PROCESSED_IMAGE_NAME[] = "test.png";

	const char SETTINGS_LOG[] = "log";
	const char SETTINGS_LOG_VALUE[] = "1";
	const int SETTINGS_LOG_VALUE_INT = 1;
	
	const char SETTINGS_LOG_TIME[] = "lTime";
	const char SETTINGS_LOG_TIME_VALUE[] = "1";
	const int SETTINGS_LOG_TIME_VALUE_INT = 1;
	
	///////////////////////////////////////////////////////////////////////////////
	//	Filters
	///////////////////////////////////////////////////////////////////////////////
	const int DIAMETER_EACH_PIXEL = 9;
	const int SIGMA_COLOR = 75;
	const int SIGMA_SPACE = 75;
	
	/// Фильтр. Размер ядра по x
	///
	/// Число не чётное
	const int KERNEL_X = 5;
	
	/// Фильтр. Размер ядра по x
	///
	/// Число не чётное
	const int KERNEL_Y = 5;

	///////////////////////////////////////////////////////////////////////////////
	//	Logger
	///////////////////////////////////////////////////////////////////////////////
	const char BLOCK_LOGGER[] = "Logger";

	const char LOGGER_LEVEL_WARNING[] = "WARN";
	const char LOGGER_LEVEL_ERROR[] = "ERROR";
	const char LOGGER_LEVEL_MESSAGE[] = "MSG";

	///////////////////////////////////////////////////////////////////////////////
	//	Log messages
	///////////////////////////////////////////////////////////////////////////////
	const char LOGGER_MESSAGE_NOISE_REMOVAL[] = "Noise filter is disabled.";
	const char LOGGER_MESSAGE_LINE_DETECTION[] = "Line detection is disabled.";
	const char LOGGER_MESSAGE_FAST_MODE[] = "Fast mode enabled.";
	const char LOGGER_MESSAGE_CREATE_DIR[] = "Folder created.";
	const char LOGGER_MESSAGE_CREATE_DIR_NOT[] = "Folder creation failed.";
	
	///////////////////////////////////////////////////////////////////////////////
	//	Errors
	///////////////////////////////////////////////////////////////////////////////
	const int ERROR_INIT = -100;
	const int ERROR_IMAGE = -200;
	const int ERROR_CLEARNING = -300;
	const int ERROR_RESIZE = -400;
	const int ERROR_NOISE_REMOVAL = -500;
	const int ERROR_LINE_DETECTION = -600;
	const int ERROR_DETECTION = -700;
	
	const char ERROR_INIT_DATABASE_ADD[] = "The file name can not be empty.";
	
	///////////////////////////////////////////////////////////////////////////////
	//	Car model
	///////////////////////////////////////////////////////////////////////////////
	const char BLOCK_CARMODEL[] = "carmodel";
	const char settings_carModel_listphoto[] = "listphoto";

	const char settings_carModel_example[] = "example";
	const char settings_carModel_example_description[] = "Brand: \"Example\"";
	const char settings_carModel_example_file[] = "example.xml";

	const char settings_block_description[] = "description";
	const char settings_description_ifnotfound[] = "Not found";
	const char settings_description_example[] = "Sample brand";

	const int settings_size_photo = 512;
}

#endif // YENOT_H
/** @} */