/**
	@file
	@brief Модуль логирования. Поддерживает логирование со временем и логирование с различными уровнями.
	@author SavaLione
	@date 1 Apr 2018
*/
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

#include <iostream>

#include "..\core\Yenot.h"
#include "..\core\Core.h"

/**
	@brief Основная функция для логирования
	
	Логирование возможно с разными уровнями и с выводом времени
	
	@param [in] level Уровень логирования
	@param [in] text Текст для логирования
*/
void logger(char *level, char *text) {
	/*
		Проверяем, нужно ли логировать.
	*/
	if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_log)) {
		/* 
			Проверка наличия файла с выводом лога в папке.
			Если файл не найден, то создаём его
		*/
		if (!check_file((char*)yenot::logger_file_name)) {
			std::ofstream fout(yenot::logger_file_name);
			fout.close();
		}
		/*
			Проверка, нужно ли логировать с выводом времени
				Создаём строки, которые будут хранить в себе значения текущего времени
				Создаём структуру SYSTEMTIME из которой будем брать текущее время
				Получаем текущее время системы и по адресу присваиваем значение структуре time
				Помещаем текущее время системы в строки.
			--------------------------------------------------------------------------------------------------------[Изменить код, т.к string не нужен
				
		*/
		if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_logTime)) {
			std::string year = "", month = "", day = "", hour = "", minute = "", second = "";
			SYSTEMTIME time;
			GetLocalTime(&time);

			if (time.wYear < 10) { year = "0"; }
			if (time.wMonth < 10) { month = "0"; }
			if (time.wDay < 10) { day = "0"; }
			if (time.wHour < 10) { hour = "0"; }
			if (time.wMinute < 10) { minute = "0"; }
			if (time.wSecond < 10) { second = "0"; }

			std::ofstream fout(yenot::logger_file_name, std::ios_base::app);

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
			std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
			fout
				<< "[" << level << "]" << text << "\n";
			fout.close();
		}
	}
}

/**
	@brief Функция для простого логирования.
	
		Используется для замера скорости выполнения некоторых алгоритмов.
	
	@param [in] x Время
	@param [in] y Итерация
*/
void logger_xy(double x, int y) {
	if (getSettings((char*)yenot::settings_block_logger, (char*)yenot::settings_log)) {
		std::ofstream fout(yenot::logger_file_name, std::ios_base::app);
		char ch_x[1024];

		sprintf(ch_x, "%f", x);

		fout << ch_x << " " << y << "\n";
		fout.close();
	}
}