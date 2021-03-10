#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"



using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void *userdata);

Mat img_aux;

int main(void) {

	Mat img_region;
	Mat img_gray;
	Mat img = imread("circulo.jpg", 1);

	int filled = 1;
	int filled_final = 0;

	cvtColor(img, img_gray, CV_BGR2GRAY);

	//imshow("Gray Image", img_gray);

	img_region = Mat(img_gray.rows, img_gray.cols, CV_8UC1);

	for (int i = 0; i < img_region.rows; i++) {
		for (int j = 0; j < img_region.cols; j++) {			
				img_region.at<uchar>(i, j) = 0;
		}
	}

	img_aux = img_region;
	//namedWindow("Region", 1);
	imshow("Region", img_region);
	setMouseCallback("Region", onMouse,0);
	waitKey(0);
	destroyAllWindows();
	img_region = img_aux;

	while (filled!=filled_final) {
		filled_final = filled;
		filled = 0;

		for (int i = 0; i < img_region.rows; i++) {
			for (int j = 0; j < img_region.cols; j++) {

				if (img_region.at<uchar>(i, j) == 255) {

					for (int x = -1; x <= 1; x++) {
						for (int y = -1; y <= 1; y++) {
							if (img_gray.at<uchar>(i + x, j + y) < 127) {
								img_region.at<uchar>(i + x, j + y) = 255;
								filled++;
								//imshow("Region", img_region);
								//waitKey(1);
							}

						}

					}
				}
			}

		}

		imshow("Region", img_region);
		waitKey(1);

	}

	imshow("Region", img_region);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void *userdata) {
	if (event == EVENT_LBUTTONDOWN){
		img_aux.at<uchar>(y, x) = 255;
	}
}