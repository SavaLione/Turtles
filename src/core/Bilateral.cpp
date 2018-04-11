/**
	\file
    \brief Описание
	\author SavaLione
*/
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

Mat mat_bilateral(char* ch_image) {

    // Window
    //namedWindow("Before" , CV_WINDOW_AUTOSIZE);

    // Load the source image
    Mat src = imread( ch_image , 1);

    // Create a destination Mat object
    Mat dst;

    // display the source image
    //imshow("Before", src);

    int i = 20; 

    bilateralFilter( src, dst, i, i*2, i*2 );

   // imshow( "Bilateral filter", dst );
    
    //waitKey(50000);

    return dst;
}