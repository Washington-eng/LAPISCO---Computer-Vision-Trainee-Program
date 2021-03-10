#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags,void* userdata);

//Mat img_aux;
Point p;

int main(void) {
	Mat img;
	Mat img_gray;
	Mat img_region;

	int filled = 1;
	int filled_final = 0;

	img = imread("gatos.jpg", 1);
	img_region = Mat(img.rows, img.cols, CV_8UC3);

	cvtColor(img, img_gray, CV_BGR2GRAY);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			img_region.at<Vec3b>(i, j)[0] = 0;
			img_region.at<Vec3b>(i, j)[1] = 0;
			img_region.at<Vec3b>(i, j)[2] = 0;
		}
	}

	imshow("Original Image", img);
	setMouseCallback("Original Image", onMouse, 0);
	waitKey(0);

	img_region.at<Vec3b>(p.y, p.x)[0] = 255;
	img_region.at<Vec3b>(p.y, p.x)[1] = 255;
	img_region.at<Vec3b>(p.y, p.x)[2] = 255;
	
	destroyAllWindows();

	while (filled != filled_final) {
		filled_final = filled;
		filled = 0;

		for (int i = 0; i < img_region.rows; i++) {
			for (int j = 0; j < img_region.cols; j++) {

				if (img_region.at<Vec3b>(i, j)[0] == 255 && img_region.at<Vec3b>(i, j)[1] == 255 && img_region.at<Vec3b>(i, j)[2] == 255) {

					for (int x = -1; x <= 1; x++) {
						for (int y = -1; y <= 1; y++) {
							
								if (img_gray.at<uchar>(i + x, j + y) < 127) {
									img_region.at<Vec3b>(i + x, j + y)[0] = 255;
									img_region.at<Vec3b>(i + x, j + y)[1] = 255;
									img_region.at<Vec3b>(i + x, j + y)[2] = 255;
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

void onMouse(int event, int x, int y,int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		p.x = x;
		p.y = y;
	}
}