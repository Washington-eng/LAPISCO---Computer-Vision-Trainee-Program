#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main() {

	Mat img = imread("Imagem.png", 1);
	Mat img_gray;
	Mat img_median;
	Mat img_Gaussian; 

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("Imagem_cinza", img_gray);

	medianBlur(img_gray, img_median, 3);
	imshow("IMG_FILTRO_MEDIANA", img_median);

	GaussianBlur(img_gray, img_Gaussian, Size(3, 3), 0);
	imshow("IMG_FILTRO_MEDIA", img_Gaussian);

	imwrite("Imagem_Mediana.png", img_median);
	imwrite("Imagem_Media.png", img_Gaussian);

	waitKey(0);
}