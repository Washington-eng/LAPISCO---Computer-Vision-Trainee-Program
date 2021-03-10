#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main() {

	Mat img = imread("Imagem.png");
	Mat img_gray;
	Mat img_maior;
	Mat img_menor;

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG-CINZA", img_gray);

	resize(img_gray, img_menor, Size(160, 120));
	imshow("IMG-MENOR", img_menor);

	resize(img_gray, img_maior, Size(640, 480));
	imshow("IMG-MAIOR", img_maior);

	imwrite("IMG-MAIOR.png", img_maior);
	imwrite("IMG-MENOR.png", img_menor);

	waitKey(0);
}