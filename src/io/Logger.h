/**
	\file
	\brief Заголовочный файл модуля логирования
	\author SavaLione
*/
#ifndef LOGGER_H
#define LOGGER_H

/** Основная функция для логирования
	\param[in] level Уровень логировния
	\param[in] text текст для логировния
*/
void logger(char *level, char *text);

/** Функция для простого логирования.
	Используется для замера скорости выполнения некоторых алгоритмов.
	\param[in] x Время
	\param[in] y Итерация
*/
void logger_xy(double x, int y);

#endif // LOGGER_H