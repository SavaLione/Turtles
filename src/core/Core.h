/**
\file
\brief Описание
\author SavaLione
*/
#ifndef CORE_H
#define CORE_H

#include <opencv2/opencv.hpp>

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////
cv::Mat mat_bilateral(char* source);
cv::Mat mat_gaussianblur(char* source);
cv::Mat mat_fastNoiseRemoval(char* source);
cv::Mat mat_fastNoiseRemovalGrey(char* source);
cv::Mat mat_blur(char* source);

///////////////////////////////////////////////////////////////////////////////
//	Line detector
///////////////////////////////////////////////////////////////////////////////
cv::Mat mat_canny(char* ch_image);

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

#endif // CORE_H