/**
\file
\brief ќписание
\author SavaLione
*/
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

#include "Yenot.h"

using namespace cv;

///////////////////////////////////////////////////////////////////////////////
//	Filters
///////////////////////////////////////////////////////////////////////////////
Mat mat_bilateral(char* ch_image) {

	// Load the source image
	Mat src = imread(ch_image, 1);

	// Create a destination Mat object
	Mat dst;

	/**
	src Ц Source 8-bit or floating-point, 1-channel or 3-channel image.
	dst Ц Destination image of the same size and type as src .
	d Ц Diameter of each pixel neighborhood that is used during filtering. If it is non-positive, it is computed from sigmaSpace.
	sigmaColor Ц Filter sigma in the color space. A larger value of the parameter means that farther colors within the pixel neighborhood (see sigmaSpace ) will be mixed together, resulting in larger areas of semi-equal color.
	sigmaSpace Ц Filter sigma in the coordinate space. A larger value of the parameter means that farther pixels will influence each other as long as their colors are close enough (see sigmaColor ). When d>0 , it specifies the neighborhood size regardless of sigmaSpace . Otherwise, d is proportional to sigmaSpace .
	*/
	bilateralFilter(src, dst, yenot::diameter_each_pixel, yenot::sigmaColor, yenot::sigmaSpace);

	return dst;
}

Mat mat_gaussianblur(char* ch_image) {
	// Load the source image
	Mat src = imread(ch_image, 1);

	// Create a destination Mat object
	Mat dst;

	GaussianBlur(src, dst, Size(yenot::gaussianblur, yenot::gaussianblur), 0, 0);

	return dst;
}