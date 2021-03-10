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
	Mat img_region_3C;

	int filled = 1;
	int filled_final = 0;

	cvtColor(img, img_gray, CV_BGR2GRAY);

	img_region = Mat(img_gray.rows, img_gray.cols, CV_8UC1);
	img_region_3C = Mat(img_region.rows, img_region.cols, CV_8UC3);

	for (int i = 0; i < img_region.rows; i++) {
		for (int j = 0; j < img_region.cols; j++) {
			img_region.at<uchar>(i, j) = 0;
		}
	}

	img_aux = img_region;
	imshow("Region", img);
	setMouseCallback("Region", onMouse, 0);
	waitKey(0);
	destroyAllWindows();
	img_region = img_aux;

	while (filled != filled_final) {
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
							}

						}

					}
				}
			}

		}		

		imshow("Region", img_region);
		waitKey(1);
		//cout << Mat(p) << endl;

	}

	Moments m = moments(img_region, true);
	Point p(m.m10 / m.m00, m.m01 / m.m00);

	for (int i = 0; i < img_region.rows; i++) {
		for (int j = 0; j < img_region.cols; j++) {
			if (img_region.at<uchar>(i, j) == 255) {
				img_region_3C.at<Vec3b>(i, j)[0] = 255;
				img_region_3C.at<Vec3b>(i, j)[1] = 0;
				img_region_3C.at<Vec3b>(i, j)[2] = 0;
			}
			else {
				img_region_3C.at<Vec3b>(i, j)[0] = 0;
				img_region_3C.at<Vec3b>(i, j)[1] = 0;
				img_region_3C.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}
	destroyAllWindows();

	circle(img_region_3C, p, 1, Scalar(0, 255, 0), 1);

	imshow("Circulo", img);
	imshow("Final", img_region_3C);
	waitKey(0);

}

void onMouse(int event, int x, int y, int flags, void *userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		img_aux.at<uchar>(y, x) = 255;
	}
}
