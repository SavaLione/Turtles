/**
\file
\brief Описание
\author SavaLione
*/
#ifndef CORE_H
#define CORE_H

#include <opencv2/opencv.hpp>

///////////////////////////////////////////////////////////////////////////////
//	Core
///////////////////////////////////////////////////////////////////////////////
cv::Mat noiseRemoval(char* source);
cv::Mat lineDetection(char* source);

void noiseRemoval(const cv::Mat& mat_in, cv::Mat& mat_out);
void lineDetection(const cv::Mat& mat_in, cv::Mat& mat_out);

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////
cv::Mat mat_bilateral(char* source);
cv::Mat mat_gaussianblur(char* source);
cv::Mat mat_fastNoiseRemoval(char* source);
cv::Mat mat_fastNoiseRemovalGrey(char* source);
cv::Mat mat_blur(char* source);

void bilateral(const cv::Mat& mat_in, cv::Mat& mat_out);
void blur(const cv::Mat& mat_in, cv::Mat& mat_out);
void fastNoiseRemovalGrey(const cv::Mat& mat_in, cv::Mat& mat_out);
void gaussianblur(const cv::Mat& mat_in, cv::Mat& mat_out);
void fastNoiseRemoval(const cv::Mat& mat_in, cv::Mat& mat_out);

///////////////////////////////////////////////////////////////////////////////
//	Line detector
///////////////////////////////////////////////////////////////////////////////
cv::Mat mat_canny(char* ch_image);

void canny(const cv::Mat& mat_in, cv::Mat& mat_out);

///////////////////////////////////////////////////////////////////////////////
//	Settings
///////////////////////////////////////////////////////////////////////////////
std::string getSettingsString(char *block, char *value);
std::string getSettingsString(char *block, char *value, char *ch_return_default);
int getSettings(char *block, char *value);
int getSettings(char *block, char *value, int i_return_default);
void setSettings(char *block, char *value, char *text);
bool check_file(char *filename);
bool check_file(char *filename, bool b_return_default);
void settings_initialization();
void buffer_initialization();
void createFile(char *file_name);

///////////////////////////////////////////////////////////////////////////////
//	Test
///////////////////////////////////////////////////////////////////////////////

void v_test();

#endif // CORE_H