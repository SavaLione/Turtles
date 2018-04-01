/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
/** Вызов программы компилятором
	\return Код завершения программы
*/
int main(int argc, char* argv[]) {
	Mat img = imread("lena.jpg");
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
    return 0;
}
