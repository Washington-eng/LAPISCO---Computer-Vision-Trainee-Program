
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include <math.h>

using namespace cv;
using namespace std;

Mat histrogram(Mat auxiliar);
Mat Equalize(Mat auxiliar);

int main(void) {
	Mat img = imread("Imagem.png", 0);
	Mat hist_img;
	Mat img_equal;
	Mat hist_img_equal;

	hist_img = histrogram(img);
	imshow("Original", img);

	resize(hist_img, hist_img, Size(2 * hist_img.cols, 2 * hist_img.rows));
	imshow("Original Hist", hist_img);

	img_equal = Equalize(img);
	hist_img_equal = histrogram(img_equal);

	imshow("Equalized", img_equal);

	resize(hist_img_equal, hist_img_equal, Size(2 * hist_img_equal.cols, 2 * hist_img_equal.rows));
	imshow("Equalized Hist", hist_img_equal);

	waitKey(0);

}


Mat histrogram(Mat auxiliar) {

	int a[256];
	int cont = 0;
	int max = 0;

	for (int i = 0; i < 256; i++) {
		a[i] = 0;
	}

	for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++) {
			a[auxiliar.at<uchar>(i, j)]++;
			cont++;
		}
	}

	for (int i = 0; i < 256; i++) {
		a[i] = a[i] * 1000 / cont;
		if (a[i] > max) {
			max = a[i];
		}
	}

	Mat hist(100, 256, CV_8UC1);

	for (int j = 0; j < hist.cols; j++) {
		for (int i = 0; i < hist.rows; i++) {
			if (i >= hist.rows - a[j]) {
				hist.at<uchar>(i, j) = 0;
			}
			else {
				hist.at<uchar>(i, j) = 255;
			}
		}
	}

	return hist;
}

Mat Equalize(Mat auxiliar) {
	int max = auxiliar.at<uchar>(0, 0);
	int min = auxiliar.at<uchar>(0,0);

	for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++ ) {
			if (auxiliar.at<uchar>(i, j) > max) {
				max = auxiliar.at<uchar>(i, j);
			}

			if (auxiliar.at<uchar>(i, j) < min) {
				min = auxiliar.at<uchar>(i, j);
			}
		}
	}

	for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++ ) {
			auxiliar.at<uchar>(i, j) = auxiliar.at<uchar>(i, j)*255/(max-min);
		}
	}

	return auxiliar;
}