#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main()
{
	Mat img = imread("Imagem.png", 1);
	
	Mat img_gray;

	cvtColor(img, img_gray, CV_BGR2GRAY);

	imshow("Imagem normal", img);
	imshow("Imagem - cinza", img_gray);

	imwrite("Imagem_gray.png", img_gray);

	waitKey(0);
}
