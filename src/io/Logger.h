/**
	@file
	@brief Заголовочный файл модуля логирования
	@author SavaLione
	@date 1 Apr 2018
*/
#ifndef LOGGER_H
#define LOGGER_H

/**
	@brief Основная функция для логирования
	
	Логирование возможно с разными уровнями и с выводом времени
	
	@param [in] level Уровень логирования
	@param [in] text Текст для логирования
*/
void logger(char *level, char *text);

/**
	@brief Функция для простого логирования.
	
		Используется для записи значений скорости выполнения алгоритмов в файл.
	
	@param [in] x Время
	@param [in] y Итерация
*/
void loggerXY(double x, int y);

#endif // LOGGER_H