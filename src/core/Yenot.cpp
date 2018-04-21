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

void moments();
void compare_new();

int main(int argc, char* argv[]) {
	//settings_initialization();

	//clearning((yenot::database_name + std::string("\\") + yenot::database_file_name), yenot::database_name);

	//databaseAddMember("somebrand");

	//Mat mat_pixel(1, 1, CV_8UC3, Scalar(110, 0, 255));

	//AddMemberPhoto("somebrand", mat_pixel);
	////

	//moments();
	compare_new();

	system("pause");
    return 0;
}


void compare() {

	IplImage *image = 0;
	image = cvLoadImage("ex.bmp", 1);

	CvMemStorage* storage1 = cvCreateMemStorage(0);

	CvSeq* contours = 0;

	IplImage *image1 = cvCreateImage(cvSize(image->width, image->height), 8, 1); ;

	cvCvtColor(image, image1, CV_BGR2GRAY);

	cvThreshold(image1, image1, 250, 255, CV_THRESH_BINARY);

	cvFindContours(image1, storage1, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));



	IplImage* cnt_img = cvCreateImage(cvSize(image->width, image->height), 8, 3);

	CvSeq* _contours = contours;

	_contours->h_next = 0;

	CvSeq* h_next;

	CvSeq* contours1 = _contours->v_next;

	cvShowImage("result1", image1);

	CvMoments moments;

	CvHuMoments HuMoments;

	//Создаём файлы, куда будем записывать моменты

	FILE *f, *f1, *f2;

	f = fopen("data.txt", "w");

	f1 = fopen("data1.txt", "w");

	f2 = fopen("data2.txt", "w");

	char buf[256];

	//Это то, что записано в файле – обучающая выборка

	char alfav[] = { "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210" };

	int i = 0;

	do {

		cvZero(cnt_img);

		h_next = contours1->h_next;

		contours1->h_next = 0;

		cvDrawContours(cnt_img, contours1, CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), 2, 1, CV_AA, cvPoint(0, 0));

		//считаем моменты здесь

		cvCvtColor(cnt_img, image1, CV_BGR2GRAY);

		//Можно было обойтись без преобразования цвета, пименив binary

		cvMoments(image1, &moments);

		cvGetHuMoments(&moments, &HuMoments);

		//Выводим моменты в файл

		sprintf(buf, "%c:\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t\n", alfav[i], HuMoments.hu1, HuMoments.hu2, HuMoments.hu3

			, HuMoments.hu4, HuMoments.hu5, HuMoments.hu6, HuMoments.hu7);

		fputs(buf, f);

		sprintf(buf, "%c:\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t\n", alfav[i], moments.m00, moments.m01, moments.m02,

			moments.m03, moments.m10, moments.m11, moments.m12, moments.m20, moments.m21, moments.m30);

		fputs(buf, f1);

		sprintf(buf, "%c:\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t\n", alfav[i], moments.mu02, moments.mu03,

			moments.mu11, moments.mu12, moments.mu20, moments.mu21, moments.mu30);

		fputs(buf, f2);

		contours1 = h_next;

		i++;

		if (h_next == NULL) break;

	} while (true);

	fclose(f);

	fclose(f1);

	fclose(f2);





	cvReleaseImage(&cnt_img);

	cvReleaseImage(&image);

	cvReleaseImage(&image1);

	cvReleaseMemStorage(&storage1);
}

void moments123() {
	Mat img1 = imread("1.png", 1);
	Mat img2;

	canny(img1, img2);

	CvMoments moments;
	CvHuMoments HuMoments;

	//cvMoments(img2, &moments);

	cvGetHuMoments(&moments, &HuMoments);
}

void thresh_callback(const cv::Mat& mat_in, cv::Mat& mat_out);
/*
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
*/
void moments()
{

	int thresh = 100;
	int max_thresh = 255;

	Mat src = imread("1.png", 1);
	Mat src_nr;
	Mat src_done;
	Mat output;

	noiseRemoval(src, src_nr);
	lineDetection(src_nr, src_done);

	thresh_callback(src_done, output);

	waitKey(0);
}

void thresh_callback(const cv::Mat& mat_in, cv::Mat& mat_out)
{
	Mat canny_output = mat_in;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;


	/// Find contours
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Get the moments
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	/// Calculate the area with the moments 00 and compare with the result of the OpenCV function
	printf("\t Info: Area and Contour Length \n");
	for (int i = 0; i< contours.size(); i++)
	{
		printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n", i, mu[i].m00, contourArea(contours[i]), arcLength(contours[i], true));
	}
	cout << endl << endl << endl << endl;
	for (int i = 0; i < contours.size(); i++) {
		cout << "Contour[" << i << "] " << mu[i].m00 << endl;
	}
	cout << endl << endl << endl << endl;

	{
		//cout << mu[].m00;
	}
}

void compare_new() {
	IplImage *src, *templ, *ftmp[6]; //ftmp is what to display on
	int i;

	// загрузка изображения
	src = cvLoadImage("1.png", 1);

	// загрузка шаблона
	templ = cvLoadImage("2.png", 1);

	int patchx = templ->width;
	int patchy = templ->height;
	int iwidth = src->width - patchx + 1;
	int iheight = src->height - patchy + 1;
	for (i = 0; i<6; ++i) {
		ftmp[i] = cvCreateImage(cvSize(iwidth, iheight), 32, 1);
	}

	// сравнение шаблона с изображением
	for (i = 0; i<6; ++i) {
		cvMatchTemplate(src, templ, ftmp[i], i);
		//              double min,max;
		//              cvMinMaxLoc(ftmp,&min,&max);
		cvNormalize(ftmp[i], ftmp[i], 1, 0, CV_MINMAX);
	}
	// показываем
	cvNamedWindow("Template");
	cvShowImage("Template", templ);
	cvNamedWindow("Image");
	cvShowImage("Image", src);

	cvNamedWindow("SQDIFF");
	cvShowImage("SQDIFF", ftmp[0]);

	cvNamedWindow("SQDIFF_NORMED");
	cvShowImage("SQDIFF_NORMED", ftmp[1]);

	cvNamedWindow("CCORR");
	cvShowImage("CCORR", ftmp[2]);

	cvNamedWindow("CCORR_NORMED");
	cvShowImage("CCORR_NORMED", ftmp[3]);

	cvNamedWindow("CCOEFF");
	cvShowImage("CCOEFF", ftmp[4]);

	cvNamedWindow("CCOEFF_NORMED");
	cvShowImage("CCOEFF_NORMED", ftmp[5]);

	// ждём нажатия клавиши
	cvWaitKey(0);
}

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

/*

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
*/

/*
Mat mat_pixel(1,1, CV_8UC3, Scalar(110,0,255));
*/