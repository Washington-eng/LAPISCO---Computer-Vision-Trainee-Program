#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void Hu_moments(Mat img);

FILE *arquivo;

int main(void) {

	Mat img;
	Mat img_gray;

	arquivo = fopen("Hu_moments.txt", "w");

	img = imread("image.jpg", 1);
	cvtColor(img, img_gray, CV_BGR2GRAY);
	Hu_moments(img_gray);

	fclose(arquivo);
}

void Hu_moments(Mat img) {
	Mat img_Canny;
	Mat img_aux;
	vector<vector<Point>> contours;

	Canny(img, img_Canny, 127, 255, 3);
	Laplacian(img_Canny, img_aux, CV_8UC1, 3);
	threshold(img_aux, img_aux, 127, 255, CV_THRESH_BINARY);
	findContours(img_aux, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	vector<Moments> m(contours.size());
	double Hu[7];

	for (int i = 0; i < contours.size(); i++) {
		m[i] = moments(contours[i], false);
		HuMoments(m[i],Hu);

		Hu[0] = m[i].nu02;
		Hu[1] = m[i].nu03;
		Hu[2] = m[i].nu11;
		Hu[3] = m[i].nu12;
		Hu[4] = m[i].nu20;
		Hu[5] = m[i].nu21;
		Hu[6] = m[i].nu30;

		cout << "Contours: nu02 = " << m[i].nu02 << endl;
		cout << "	  nu03 = " << m[i].nu03 << endl;
		cout << "	  nu11 = " << m[i].nu11 << endl;
		cout << "	  nu12 = " << m[i].nu12 << endl;
		cout << "     nu20 = " << m[i].nu20 << endl;
		cout << "	  nu21 = " << m[i].nu21 << endl;
		cout << "	  nu30 = " << m[i].nu30 << endl << endl;

		fprintf(arquivo, "Contour %d:\nnu02 = %f\nnu03 = %f\nnu11 = %f\nnu12 = %f\nnu20 = %f\nnu21 = %f\nnu30 = %f\n\n\n", i,
			Hu[0], Hu[1], Hu[2], Hu[3], Hu[4], Hu[5], Hu[6]);
	}

}