#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

int main() {
	FILE* arquivo;

	arquivo = fopen("Matriz_img.txt", "w");
	
	
	Mat img = imread("Imagem.png",1);
	Mat img_gray;
	int i, j;

	cvtColor(img, img_gray, CV_RGB2GRAY);
	imshow("IMG_CINZA", img_gray);	
	
	for (i = 0; i < img_gray.rows; i++) {
		for (j = 0; j < img_gray.cols; j++) {
			fprintf(arquivo,"%d\t",img_gray.at<uchar>(i, j));
		}
		fprintf(arquivo,";\n");
	}
	fclose(arquivo);

	waitKey(0);
}