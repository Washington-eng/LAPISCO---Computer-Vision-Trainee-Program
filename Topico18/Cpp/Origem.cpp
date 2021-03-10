#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main(void) {
	Mat img = imread("Imagem.png", 1);
	Mat img_Laplace;
	Mat img_equalized;
	Mat img_gray;

	cvtColor(img, img_gray, CV_BGR2GRAY);

	imshow("Gray", img_gray);

	Laplacian(img_gray, img_Laplace, CV_16S, 1);
	convertScaleAbs(img_Laplace, img_Laplace);

	imshow("Laplacian", img_Laplace);

	equalizeHist(img_Laplace, img_equalized);
	 
	imshow("Equalized", img_equalized);

	waitKey(0);	
	
}