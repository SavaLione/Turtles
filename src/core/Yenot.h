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
	@brief Работа с изображениями, xml(yaml) файлами
*/
/**
	@defgroup server Сервер
	@brief Сервер. Должен принимать фото
*/
/**
	@defgroup database Database
	@brief Удобное добавление trainhaar.xml файлов
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
	///	[Core]
	/// ...
	/// @endcode
	const char BLOCK_CORE[] = "Core";
	
	/// Быстрый режим.
	///
	/// Название параметра
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
	/// Название параметра
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

	/// Поиск линий на изображении
	///
	/// Название параметра
	///
	/// Замедляет работу программы
	const char SETTINGS_LINE_DETECTION[] = "lDetection";
	/// Поиск линий на изображении
	///
	/// Стандартное значение
	const char SETTINGS_LINE_DETECTION_VALUE[] = "1";
	/// Поиск линий на изображении
	///
	/// Стандартное значение
	const int SETTINGS_LINE_DETECTION_VALUE_INT = 1;

	/// Алгоритм поиска объекта на изображении
	///
	/// Название параметра
	const char SETTINGS_DETECTION[] = "detection";
	/// Алгоритм поиска объекта на изображении
	///
	/// Стандартное значение
	const char SETTINGS_DETECTION_VALUE[] = "1";
	/// Алгоритм поиска объекта на изображении
	///
	/// Стандартное значение
	const int SETTINGS_DETECTION_VALUE_INT = 1;

	/// Нужно ли сохранять изображение после работы алгоритма
	///
	/// Название параметра
	const char SETTINGS_SAVE_PROCESSED_IMAGE[] = "sImage";
	/// Нужно ли сохранять изображение после работы алгоритма
	///
	/// Стандартное значение
	const char SETTINGS_SAVE_PROCESSED_IMAGE_VALUE[] = "0";
	/// Нужно ли сохранять изображение после работы алгоритма
	///
	/// Стандартное значение
	const int SETTINGS_SAVE_PROCESSED_IMAGE_VALUE_INT = 0;
	/// Нужно ли сохранять изображение после работы алгоритма
	///
	/// Название файла
	const char SETTINGS_SAVE_PROCESSED_IMAGE_NAME[] = "test.png";

	/// Модуль логирования
	///
	/// Название параметра
	const char SETTINGS_LOG[] = "log";
	/// Модуль логирования
	///
	/// Стандартное значение
	const char SETTINGS_LOG_VALUE[] = "1";
	/// Модуль логирования
	///
	/// Стандартное значение
	const int SETTINGS_LOG_VALUE_INT = 1;
	
	/// Модуль логирования. Логирование с выводом времени
	///
	/// Название параметра
	const char SETTINGS_LOG_TIME[] = "lTime";
	/// Модуль логирования. Логирование с выводом времени
	///
	/// Стандартное значение
	const char SETTINGS_LOG_TIME_VALUE[] = "1";
	/// Модуль логирования. Логирование с выводом времени
	///
	/// Стандартное значение
	const int SETTINGS_LOG_TIME_VALUE_INT = 1;
	
	/// Модуль распознования логотипа на фото
	///
	/// Размер шаблона
	const char SETTINGS_TEMPLATE_SIZE[] = "templatesize";
	/// Модуль логирования
	///
	/// Стандартное значение
	const char TEMPLATE_SIZE_STR[] = "20";
	/// Модуль логирования
	///
	/// Стандартное значение
	const int TEMPLATE_SIZE = 20;
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
	
	/// Блок модуля логирования.
	///
	///	ini файл
	/// @code
	///	[Logger]
	/// ...
	/// @endcode
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
	const int ERROR_DATABASE = -800;
	
	const char ERROR_INIT_DATABASE_ADD[] = "The file name can not be empty.";
	const char ERROR_DATABASE_ADD_ARGUMENTS[] = "Few arguments";
	
	///////////////////////////////////////////////////////////////////////////////
	//	Description
	///////////////////////////////////////////////////////////////////////////////
	
	/// Блок модуля поиска описания логотипа
	///
	///	ini файл
	/// @code
	///	[description]
	/// ...
	/// @endcode

	const char BLOCK_DESCRIPTION[] = "description";
	
	const char CAR_MODEL_EXAMPLE[] = "example";
	const char CAR_MODEL_EXAMPLE_DESCRIPTION[] = "Brand: \"Example\"";
	const char CAR_MODEL_EXAMPLE_FILE[] = "example.xml";

	const char DESCRIPTION_NOT_FOUND[] = "The brand name is not set";
	
	const int SIZE_PHOTO = 512;
}

#endif // YENOT_H
/** @} */