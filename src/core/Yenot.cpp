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

int main(int argc, char* argv[]) {

	cv::Mat mat_image = cv::imread("a.png", 1);
	cv::Mat mat_out;

	lineDetection(mat_image, mat_out);
	mat_image = mat_out;

	//FileStorage fs("example_001.xml", FileStorage::WRITE);
	//fs << "image" << mat_image;
	//fs << "some" << mat_image;
	//fs.release();

	//FileStorage fs;
	//fs.open("example_001.xml", FileStorage::READ);
	//fs["image"] >> mat_out;
	//imwrite("new.png", mat_out);
	
	std::vector<string> stringVector;
	//stringVector.insert(stringVector.end(), "");

	FileStorage fs("example.xml", FileStorage::WRITE);
	fs << "stringVector" << stringVector;
	fs.release();

	std::vector<string> stringVectorNew;
	FileStorage fsNew;
	fsNew.open("example.xml", FileStorage::READ);
	fsNew["stringVector"] >> stringVectorNew;
	
	stringVectorNew.insert(stringVector.end(), "SOMETHING");

	FileStorage fsNew1("example.xml", FileStorage::WRITE);
	fsNew1 << "stringVector" << stringVectorNew;
	fsNew1.release();



	system("pause");
    return 0;
}

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
char* image = argc == 2 ? argv[1] : "a.png";

cv::Mat out;
cv::Mat mat_image = cv::imread(image, 1);

settings_initialization();

noiseRemoval(mat_image, out);
mat_image = out;

lineDetection(mat_image, out);
mat_image = out;
*/