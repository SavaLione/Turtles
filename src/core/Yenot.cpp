/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <iostream>
#include <Windows.h>

#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <opencv2\opencv.hpp>

#include <ctime>
#include <filesystem>

#include "Yenot.h"
#include "..\core\Core.h"
#include "..\io\Logger.h"

using namespace cv;
using namespace std;

void readme();

int main() {

	return 0;
}

void readme()
{
	std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl;
}

/*
//settings_initialization();

//clearning((yenot::database_name + std::string("\\") + yenot::database_file_name), yenot::database_name);

//databaseAddMember("somebrand");

//Mat mat_pixel(1, 1, CV_8UC3, Scalar(110, 0, 255));

//AddMemberPhoto("somebrand", mat_pixel);
////

//moments();
*/