#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main() {

	Mat img = imread("Imagem.png", 1);
	Mat img_gray;
	Mat img_filtro_canny;

	cvtColor(img, img_gray, CV_RGB2GRAY);

	imshow("IMG-CINZA", img_gray);

	Canny(img_gray, img_filtro_canny,200, 150);

	imshow("IMG-CANNY", img_filtro_canny);
	imwrite("Imagem-Canny.png", img_filtro_canny);

	waitKey(0);
}