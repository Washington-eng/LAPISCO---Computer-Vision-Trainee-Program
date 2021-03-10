#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main() {

	Mat img = imread("Imagem.png");
	Mat img_gray;
	Mat img_threshold;

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG-CINZA", img_gray);

	threshold(img_gray, img_threshold, 50, 255, 0);
	imshow("IMG-THRESHOLD", img_threshold);
	imwrite("IMG-THRESHOLD.png", img_threshold);

	waitKey(0);
}