#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"



using namespace cv;
using namespace std;

int main(void) {

	Mat img_region;
	Mat img_gray;
	Mat img = imread("circulo.jpg", 1);
	
	int filled=1;
	int filled_final=0;

	cvtColor(img, img_gray, CV_BGR2GRAY);

	//imshow("Gray Image", img_gray);
	
	img_region=Mat(img_gray.rows, img_gray.cols, CV_8UC1);
	
	for (int i = 0; i < img_region.rows; i++) {
		for (int j = 0; j < img_region.cols; j++) {
			if (i == 160 && j== 200) {
				img_region.at<uchar>(i, j) = 255;
			}
			else {
				img_region.at<uchar>(i, j) = 0;
			}
		}
	}

	//imshow("teste", img_region);
	//waitKey(0);
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
		
	}
}
