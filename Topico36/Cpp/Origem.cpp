#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void) {

	Mat img;
	Mat img_gray;
	Mat img_OTSU;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	img = imread("Imagem.png", 1);
	//imshow("Image", img);
	cvtColor(img, img_gray, CV_BGR2GRAY);
	threshold(img_gray, img_OTSU, 50, 255, THRESH_OTSU);

	imshow("OTSU", img_OTSU);
	waitKey(0);

	for (int i = 0; i < 9; i++) {
		erode(img_OTSU, img_OTSU, element);
		imshow("Erode", img_OTSU);
		waitKey(1000);

	}


}