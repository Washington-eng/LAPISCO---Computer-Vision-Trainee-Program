#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {

	Mat img = imread("Imagem.png", 1);
	Mat img_gray;
	//Mat grad_x;
	//Mat grad_y;
	//Mat img_final;
	Mat Sobel;
	int i, j;
	int dx, dy;
	
	
	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG_inicial_gray", img_gray);

	/* //Convolução realizada com as funçoes disponibilizadas pela openvc

	Sobel(img_gray, grad_x, CV_8U, 1, 0);
	Sobel(img_gray, grad_y, CV_8U, 0, 1);

	addWeighted(grad_x, 0.5, grad_y, 0.5, 0, img_final);
	
	imshow("IMG_final", img_final);
	imwrite("Imagem_bordas.png", img_final);
	*/


	//Convolução utilizando as matrizes de kernel 3x3 de Sobel
	Sobel = img_gray;
	int matriz[220][220];

	for(i=0;i<img_gray.rows;i++)
		for (j = 0; j < img_gray.cols; j++) {
			matriz[i][j] = img_gray.at<uchar>(i, j);
		}

	for(i=1;i<img_gray.rows-1;i++)
		for (j = 1; j < img_gray.cols - 1; j++) {
			dx = (-1)*matriz[i - 1][j - 1] + (1)*matriz[i - 1][j + 1] + (-2)*matriz[i][j - 1] + (2)*matriz[i][j + 1] + (-1)*matriz[i + 1][j - 1] + (1)*matriz[i + 1][j + 1];
			dy = (1)*matriz[i - 1][j - 1] + (2)*matriz[i - 1][j] + (1)*matriz[i-1][j + 1] + (-1)*matriz[i+1][j - 1] + (-2)*matriz[i + 1][j] + (-1)*matriz[i + 1][j + 1];
			Sobel.at<uchar>(i, j) = (int)sqrt(pow(dx, 2) + pow(dy, 2));
		}

	imshow("IMG_final", Sobel);
	imwrite("Imagem_bordas1.png", Sobel);


	waitKey(0);
}