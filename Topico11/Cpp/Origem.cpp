#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("quadrado.png", 1);
	Mat img_gray;
	Mat img_gray_modificada;
	int i, j;
	int x, y;
	int cont=0;
	int soma_i=0;
	int soma_j = 0;

	FILE* arquivo;
	arquivo = fopen("arquivo_matriz.txt", "w");

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG-CINZA", img_gray);

	img_gray_modificada = img_gray;
	
	for(i=0;i<img_gray_modificada.rows;i++){
		
		for (j = 0; j < img_gray_modificada.cols; j++) {
			
			if (img_gray_modificada.at<uchar>(i, j) == 0) {
				
				soma_i = soma_i + i;
				soma_j = soma_j + j;
				cont++;
			}
		}
	}
	
	x = (soma_i) / cont;		//o circulo só fica centralizado se o quadrado possuir dimensões ímpares.
	y = (soma_j) / cont;


	circle(img_gray_modificada, {x,y}, 3, Scalar(255, 255, 255));


	imshow("IMG-MODIF", img_gray_modificada);

	waitKey(0);
}