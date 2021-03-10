#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include <math.h>

using namespace cv;

Mat histogram(Mat auxiliar);
Mat Sobel_1(Mat auxiliar);

int main(void) {
	Mat img_gray;
	Mat img_Sobel;
	Mat img_gray_hist;
	Mat img_Sobel_hist;

	Mat img = imread("Imagem.png", 1);

	//img_gray = img;
	cvtColor(img, img_gray, CV_BGR2GRAY);
	imshow("gray Image", img_gray);
	img_gray_hist = histogram(img_gray);
	imshow("gray image histogram", img_gray_hist);

	img_Sobel = Sobel_1(img_gray);
	imshow("Sobel", img_Sobel);
	img_Sobel_hist = histogram(img_Sobel);
	imshow("Sobel histogram", img_Sobel_hist);
	waitKey(0);
	
}

Mat histogram(Mat auxiliar) {

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
Mat Sobel_1(Mat auxiliar) {

	int m[220][220];

	int Sh;
	int Sv;
	//Mat Sh;
	//Sh = Mat(auxiliar.rows, auxiliar.cols, CV_8UC1);
	//Mat Sv;
	//Sv = Mat(auxiliar.rows, auxiliar.cols, CV_8UC1);
	Mat Sobel=auxiliar;
	//Sobel = Mat(auxiliar.rows, auxiliar.cols, CV_8UC1);
	
	for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++) {
			m[i][j] = auxiliar.at<uchar>(i, j);
		}
	}

	for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++) {
			if (i == 0 && j == 0) {
				Sh = 2 *m[i][j + 1] + 1 * m[i + 1][j + 1];
				Sv= 2 * m[i + 1][j] + 1 * m[i + 1][j + 1];
			}
			else if (i == 0 && j != auxiliar.cols - 1) {
				Sh = -2 * m[i][j - 1] + 2 * m[i][j + 1] - 1 * m[i + 1][j - 1] + 1 *m[i + 1][j + 1];
				Sv = 1 * m[i + 1][j - 1] + 2 * m[i + 1][j] + 1 * m[i + 1][j + 1];
			}
			else if (i == 0 && j == auxiliar.cols - 1) {
				Sh = -2 * m[i][j - 1] - 1 * m[i + 1][j - 1];
				Sv = 2 * m[i + 1][j] + 1 * m[i + 1][j - 1];
			}
			else if (i == auxiliar.rows - 1 && j == 0) {
				Sh = 2 * m[i][j + 1] + 1 * m[i - 1][j + 1];
				Sv = -2 * m[i - 1][j] - 1 * m[i - 1][j + 1];
			}
			else if (i == auxiliar.rows - 1 && j != auxiliar.cols - 1) {
				Sh = -2 * m[i][j - 1] + 2 *m[i][j + 1] - 1 * m[i - 1][j - 1] + 1 * m[i - 1][j + 1];
				Sv = -1 * m[i - 1][j - 1] - 2 *m[i - 1][j] - 1 * m[i - 1][j + 1];
			}
			else if (i == auxiliar.rows - 1 && j == auxiliar.cols - 1) {
				Sh = -2 * m[i][j - 1] - 1 * m[i - 1][j - 1];
				Sv = -2 * m[i - 1][j] - 1 * m[i - 1][j - 1];
			}
			else if (i != 0 && j == 0) {
				Sh = (1)*m[i - 1][j + 1] + 2 * m[i][j + 1] + 1 * m[i + 1][j + 1];
				Sv = (2)*m[i - 1][j] - 2 * m[i + 1][j] + 1 * m[i + 1][j + 1] - 1 * m[i - 1][j + 1];
			}
			else if (i != 0 && j == auxiliar.cols - 1) {
				Sh = (-1)*m[i - 1][j - 1] - 1 * m[i + 1][j - 1] - 2 * m[i][j - 1];
				Sv = (2)*m[i - 1][j] - 2 * m[i + 1][j] + 1 * m[i + 1][j - 1] - 1 * m[i - 1][j - 1];
			}
			else {
				Sh = (-1)*m[i - 1][j - 1] + 1 * m[i - 1][j + 1] - 2 * m[i][j - 1] + 2 * m[i][j + 1] - 1 * m[i + 1][j - 1] + 1 * m[i + 1][j + 1];
				Sv = (-1)*m[i - 1][j - 1] - 2 * m[i - 1][j] - 1 * m[i - 1][j + 1] + 1 * m[i + 1][j - 1] + 2 * m[i + 1][j] + 1 * m[i + 1][j + 1];
			}

			Sobel.at<uchar>(i, j) = (int)sqrt(pow(Sh, 2) + pow(Sv, 2));
		}
	}
	//Mascara horizontal (Sh) e Mascara Vertical (Sv)
	/*for (int i = 0; i < auxiliar.rows; i++) {
		for (int j = 0; j < auxiliar.cols; j++) {
			if (i == 0 && j == 0) {
				Sh.at<uchar>(i, j) = 2 * auxiliar.at<uchar>(i, j + 1) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
				Sv.at<uchar>(i, j) = 2 * auxiliar.at<uchar>(i + 1, j) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
			}
			else if (i == 0 && j!=auxiliar.cols-1) {
				Sh.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i, j - 1) + 2 * auxiliar.at<uchar>(i, j + 1) - 1 * auxiliar.at<uchar>(i + 1, j - 1) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
				Sv.at<uchar>(i, j) = 1 * auxiliar.at<uchar>(i+1, j - 1) + 2 * auxiliar.at<uchar>(i+1, j) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
			}
			else if (i == 0 && j == auxiliar.cols - 1) {
				Sh.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i, j - 1) - 1 * auxiliar.at<uchar>(i + 1, j - 1);
				Sv.at<uchar>(i, j) = 2 * auxiliar.at<uchar>(i + 1, j) + 1 * auxiliar.at<uchar>(i + 1, j - 1);
			}
			else if (i == auxiliar.rows - 1 && j == 0) {
				Sh.at<uchar>(i, j) = 2 * auxiliar.at<uchar>(i, j + 1) + 1 * auxiliar.at<uchar>(i - 1, j + 1);
				Sv.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i - 1, j) - 1 * auxiliar.at<uchar>(i - 1, j + 1);
			}
			else if (i == auxiliar.rows-1 && j != auxiliar.cols - 1) {
				Sh.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i, j - 1) + 2 * auxiliar.at<uchar>(i, j + 1) - 1 * auxiliar.at<uchar>(i - 1, j - 1) + 1 * auxiliar.at<uchar>(i - 1, j + 1);
				Sv.at<uchar>(i, j) = -1 * auxiliar.at<uchar>(i - 1, j - 1) - 2 * auxiliar.at<uchar>(i - 1, j) - 1 * auxiliar.at<uchar>(i - 1, j + 1);
			}
			else if (i == auxiliar.rows-1 && j == auxiliar.cols - 1) {
				Sh.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i, j - 1) - 1 * auxiliar.at<uchar>(i - 1, j - 1);
				Sv.at<uchar>(i, j) = -2 * auxiliar.at<uchar>(i - 1, j) - 1 * auxiliar.at<uchar>(i - 1, j - 1);
			}
			else if (i != 0 && j == 0) {
				Sh.at<uchar>(i, j) = (1)*auxiliar.at<uchar>(i - 1, j + 1) + 2 * auxiliar.at<uchar>(i, j + 1) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
				Sv.at<uchar>(i, j) = (2)*auxiliar.at<uchar>(i - 1, j) - 2 * auxiliar.at<uchar>(i + 1, j) + 1 * auxiliar.at<uchar>(i + 1, j + 1) - 1 * auxiliar.at<uchar>(i - 1, j + 1);
			}
			else if (i != 0 && j == auxiliar.cols - 1) {
				Sh.at<uchar>(i, j) = (-1)*auxiliar.at<uchar>(i - 1, j - 1) - 1 * auxiliar.at<uchar>(i + 1, j - 1) - 2 * auxiliar.at<uchar>(i, j - 1);
				Sv.at<uchar>(i, j) = (2)*auxiliar.at<uchar>(i - 1, j) - 2 * auxiliar.at<uchar>(i + 1, j) + 1 * auxiliar.at<uchar>(i + 1, j - 1) - 1 * auxiliar.at<uchar>(i - 1, j - 1);
			}
			else {
				Sh.at<uchar>(i, j) = (-1)*auxiliar.at<uchar>(i - 1, j - 1) + 1 * auxiliar.at<uchar>(i - 1, j + 1) - 2 * auxiliar.at<uchar>(i, j - 1) + 2 * auxiliar.at<uchar>(i, j + 1) - 1 * auxiliar.at<uchar>(i + 1, j - 1) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
				Sv.at<uchar>(i, j) = (-1)*auxiliar.at<uchar>(i - 1, j - 1) - 2 * auxiliar.at<uchar>(i - 1, j) - 1 * auxiliar.at<uchar>(i - 1, j + 1) + 1 * auxiliar.at<uchar>(i + 1, j - 1) + 2 * auxiliar.at<uchar>(i + 1, j) + 1 * auxiliar.at<uchar>(i + 1, j + 1);
			}

			Sobel.at<uchar>(i,j) =(int) sqrt((int)pow(Sh.at<uchar>(i, j), 2)+ (int)pow(Sv.at<uchar>(i, j), 2));
		}
	}
	*/
	return Sobel;
}
