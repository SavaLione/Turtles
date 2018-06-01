/**
	@file
	@brief Модуль логирования. Поддерживает логирование со временем и логирование с различными уровнями.
	@author SavaLione
	@date 1 Apr 2018
*/
/**
	@defgroup loggercpp Logger.cpp
	@ingroup yenot
	@{
*/
#include <Windows.h>
#include <fstream>

#include "..\core\Yenot.h"
#include "..\core\Settings.h"

using namespace std;
using namespace yenot;

/**
	@brief Основная функция для логирования
	
	Логирование возможно с разными уровнями и с выводом времени
	
	@param [in] level Уровень логирования
	@param [in] text Текст для логирования
*/
void logger(char *level, char *text) {
	/// Проверяем, нужно ли логировать.
	if (getSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG, SETTINGS_LOG_VALUE_INT)) {
		/// Проверка наличия файла с выводом лога в папке.
		///
		/// Если файл не найден, то создаём его
		if (!checkFile((char*)FILE_NAME_LOGGER)) {
			ofstream fout(FILE_NAME_LOGGER);
			fout.close();
		}
		/// Проверка, нужно ли логировать с выводом времени
		/// 
		/// Если нужно ли логировать с выводом времени, то
		/// 
		/// 	Создаём строки, которые будут хранить в себе значения текущего времени
		///
		/// 	Создаём структуру SYSTEMTIME из которой будем брать текущее время
		/// 
		/// 	Получаем текущее время системы и по адресу присваиваем значение структуре time
		/// 
		/// 	Помещаем текущее время системы в строки.
		/// 
		/// 	Открываем файл для логирования. Открываем файл для записи в конце.
		///
		///		Записываем данные в файл
		///
		///		Закрываем файл
		///
		///	иначе
		///
		///		Открываем файл для логирования. Открываем файл для записи в конце.
		///
		///		Записываем данные в файл
		///
		///		Закрываем файл
		if (getSettings((char*)BLOCK_LOGGER, (char*)SETTINGS_LOG_TIME, SETTINGS_LOG_TIME_VALUE_INT)) {
			char *year = "", *month = "", *day = "", *hour = "", *minute = "", *second = "";
			SYSTEMTIME time;
			GetLocalTime(&time);

			if (time.wYear < 10) { year = "0"; }
			if (time.wMonth < 10) { month = "0"; }
			if (time.wDay < 10) { day = "0"; }
			if (time.wHour < 10) { hour = "0"; }
			if (time.wMinute < 10) { minute = "0"; }
			if (time.wSecond < 10) { second = "0"; }

			ofstream fout(FILE_NAME_LOGGER, ios_base::app);
			
			/// Записываем данные в файл.
			///
			///	Пример:
			/// @code
			/// [2018/05/02 17:17:03] [WARN]Folder created.
			/// @endcode
			fout
				<< "["
				<< year << time.wYear << "/"
				<< month << time.wMonth << "/"
				<< day << time.wDay << " "
				<< hour << time.wHour << ":"
				<< minute << time.wMinute << ":"
				<< second << time.wSecond << "] "
				<< "[" << level << "]" << text
				<< "\n";
			fout.close();
		} else {
			ofstream fout(FILE_NAME_LOGGER, ios_base::app);
			/// Записываем данные в файл.
			///
			///	Пример:
			/// @code
			/// [WARN]Folder created.
			/// @endcode
			fout << "[" << level << "]" << text << "\n";
			fout.close();
		}
	}
}
/** @} */