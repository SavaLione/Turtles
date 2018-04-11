/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <opencv2/opencv.hpp>

#include "Bilateral.h"

int main(int argc, char* argv[]) {

    
    
    cv::imwrite("AAA.jpg", mat_bilateral("lena.jpg"));

    return 0;
}