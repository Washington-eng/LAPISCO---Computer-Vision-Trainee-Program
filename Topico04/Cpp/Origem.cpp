#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {

	Mat img = imread("Imagem.png", 1);
	Mat img_HSV;
	vector<Mat> img_canais;
	
	cvtColor(img, img_HSV, CV_BGR2HSV);
	split(img_HSV, img_canais);

	imshow("IMG_H", img_canais[0]);
	imshow("IMG_S", img_canais[1]);
	imshow("IMG_V", img_canais[2]);

	imwrite("Imagem_H.jpg", img_canais[0]);
	imwrite("Imagem_S.jpg", img_canais[1]);
	imwrite("Imagem_V.jpg", img_canais[2]);

	waitKey(0);

}