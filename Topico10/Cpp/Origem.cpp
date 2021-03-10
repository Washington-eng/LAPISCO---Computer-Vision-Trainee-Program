#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("Imagem.png", 1);
	Mat img_gray;
	int i, j;

	FILE* arquivo;

	arquivo = fopen("arquivo_matriz.txt", "w");

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG-CINZA", img_gray);

	for (i = 0; i < img_gray.rows; i++) {
		for (j = 0; j < img_gray.cols; j++) {
			if (img_gray.at<uchar>(i, j) > 100) {
				img_gray.at<uchar>(i, j) = 255;
			}
			else {
				img_gray.at<uchar>(i, j) = 0;
			}
			fprintf(arquivo, "%d\t", img_gray.at<uchar>(i, j));
		}
		fprintf(arquivo, "\n");
	}

	fclose(arquivo);
	imshow("TESTE", img_gray);

	waitKey(0);
}