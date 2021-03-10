#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	
	Mat img = imread("Imagem.png",1);

	vector<Mat> bgr_canais;

	split(img,bgr_canais);

	imshow("ImagemChannel Blue",bgr_canais[0]);
	imshow("ImagemChannel Green",bgr_canais[1]);
	imshow("ImagemChannel Red",bgr_canais[2]);

	imwrite("Imagem_G.jpg",bgr_canais[0]);
	imwrite("Imagem_B.jpg",bgr_canais[1]);
	imwrite("Imagem_R.jpg",bgr_canais[2]);

	waitKey(0);
}