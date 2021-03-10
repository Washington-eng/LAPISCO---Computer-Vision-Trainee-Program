#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat img;
	Mat img_gray;
	Mat img_thresh;
	   
	img = imread("Imagem.png", 1);
	
	cvtColor(img, img_gray, CV_BGR2GRAY);

	adaptiveThreshold(img_gray, img_thresh, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 3, 5);

	imshow("Modified Image", img_thresh);
	waitKey(0);
}