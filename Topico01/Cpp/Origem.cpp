#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	
	Mat img = imread("Imagem.png", 1);
	imshow("Teste", img);
	imwrite("teste.png", img);

	waitKey(0);
}
