/**
	@file
	@brief Ядро проекта. Содержит все главные и вспомогательные функции для определения марки автомобиля
	@author SavaLione
	@date 12 Apr 2018
*/
/**
	@defgroup coreh Core.h
	@ingroup core
	@{
*/
#ifndef CORE_H
#define CORE_H

#include <opencv2/opencv.hpp>

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
void noiseRemoval(const cv::Mat& mat_in, cv::Mat& mat_out);

/**
	@brief Функция для обработки изображений.
	
	Проверяет, нужно ли находить линии на изображении.
	
	Также проверяем режим обработки изображений. Быстрый или нет.
	
	Для обычного режима используется - canny(mat_in, mat_out);
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void lineDetection(const cv::Mat& mat_in, cv::Mat& mat_out);

/**
	@brief Функция для добавления файла с каскадом в файл с информацией о каскадах
	
	@param [in] filename Название каскада с расширением
*/
void databaseAdd(std::string filename);

/**
	@brief Функция для очистки дубликатов в векторе
	
	@param [in] filename Название и путь к файлу
	@param [in] variable Вектор, в котором нужно удалить дубликаты
*/
void clearning(std::string filename, std::string variable);

/**
	@brief Функция для поиска объекта на фото
	
	@param [in] mat_logo Матрица с изображением
	@param [in] cascadefile Файл с каскадом
	@return Результат работы. true - объект найден, false - объект не найден
*/
bool detectionLogo(const cv::Mat& mat_logo, std::string cascadefile);

/**
	@brief Модуль поиска объектов на фото
	
	Поиск объектов на фото
	
	Вывод информации
	
	@param [in] mat_logo Матрица с изображением
*/
void detection(const cv::Mat& mat_logo);

///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////

/**
	@brief Модуль настроек.
	
	При отсутствии файла настроек, создаёт его
*/
void settingsInitialization();

/**
	@brief Функция для поиска описания марки по файлу с каскадом Хаара
	@param [in] value Название файла
	@return Искомое описание марки
*/
std::string description(std::string value);

///////////////////////////////////////////////////////////////////////////////
//	Line detector
///////////////////////////////////////////////////////////////////////////////

/**
	@brief Функция для обработки изображений.
	
	Поиск границ на изображении. Метод canny.
	
	@param [in] mat_in Матрица с изображением для обработки
	@param [out] mat_out Матрица с обработанным изображением, которая будет возвращена
*/
void canny(const cv::Mat& mat_in, cv::Mat& mat_out);

#endif // CORE_H
/** @} */