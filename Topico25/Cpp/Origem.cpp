#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void* userdata);
void scanCloser(Mat &src, Mat &src2, int i, int j,int channel);
//Mat img_aux;
Point p;
int filled = 1;
int filled_final = 0;

int main(void) {
	Mat img;
	Mat img_gray;
	Mat img_region;

	

	img = imread("formas.jpg", 1);
	img_region = Mat(img.rows, img.cols, CV_8UC3);

	cvtColor(img, img_gray, CV_BGR2GRAY);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			img_region.at<Vec3b>(i, j)[0] = 0;
			img_region.at<Vec3b>(i, j)[1] = 0;
			img_region.at<Vec3b>(i, j)[2] = 0;
		}
	}

	for (int region_counter = 1; region_counter <= 3; region_counter++) {
		imshow("Original Image", img);
		setMouseCallback("Original Image", onMouse, 0);
		waitKey(0);

		img_region.at<Vec3b>(p.y, p.x)[region_counter-1] = 255;
		destroyAllWindows();

		filled = 0;
		filled_final = 1;
		while (filled != filled_final) {
			filled_final = filled;
			filled = 0;

			for (int i = 0; i < img_region.rows; i++) {
				for (int j = 0; j < img_region.cols; j++) {
					
					if (img_gray.at<uchar>(i, j) < 150) {
						if (region_counter == 1) {
							if(img_region.at<Vec3b>(i, j)[0] == 255)
								scanCloser(img_gray, img_region, i, j, region_counter - 1);						
						}

						if (region_counter == 2) {
							if(img_region.at<Vec3b>(i, j)[1] == 255)
								scanCloser(img_gray, img_region, i, j, region_counter - 1);
						}

						if (region_counter == 3) {
							if (img_region.at<Vec3b>(i, j)[2] == 255)
								scanCloser(img_gray, img_region, i, j, region_counter - 1);
						}
					}
				}

			}

		}
		imshow("Region", img_region);
		waitKey(2000);
		destroyWindow("Region");
	}

	imshow("Region", img_region);
	waitKey(0);
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		p.x = x;
		p.y = y;
	}
}

void scanCloser(Mat &src,Mat &src2,  int i, int j,int channel) {

	for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {

				if (src.at<uchar>(i + x, j + y) < 127) {
					src2.at<Vec3b>(i + x, j + y)[channel] = 255;
					filled++;
					//imshow("Region", src2);
					//waitKey(1);
				}
			}
	}
}