/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <ctime>
#include <filesystem>

#include "Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;

Mat mat_filter(Mat in);

int main(int argc, char* argv[]) {
	char* image = argc == 2 ? argv[1] : "a.png";

	cv::Mat out;
	cv::Mat mat_image = cv::imread(image, 1);

	settings_initialization();
	buffer_initialization();

	noiseRemoval(mat_image, out);
	lineDetection(mat_image, out);

	cv::imwrite(yenot::buffer_file_name_img, out);

	system("pause");
    return 0;
}

Mat mat_filter(Mat in) {

	return in;
}

/*
for (int i = 0; i <= 4; i++) {
for (int ii = 0; ii <= 16; ii++) {
for (int iii = 0; iii <= 16; iii++) {
char ch = getRandom();
while (ch == getRandom()) {
ch = getRandom();
}
cout << ch;
}
cout << endl;
}
system("pause");
}
*/

/*
WIN32_FIND_DATAW wfd;
HANDLE const hFind = FindFirstFileW(L"./*", &wfd);
if (INVALID_HANDLE_VALUE != hFind)
{
do
{
std::wcout << &wfd.cFileName[0] << std::endl;
} while (NULL != FindNextFileW(hFind, &wfd));

FindClose(hFind);
}
*/

/*
mat_image = noiseRemoval(image);
cv::imwrite(yenot::buffer_file_name_img, mat_image);
system("pause");


mat_image = lineDetection((char*)yenot::buffer_file_name_img);
cv::imwrite(yenot::buffer_file_name_img, mat_image);
system("pause");


*/