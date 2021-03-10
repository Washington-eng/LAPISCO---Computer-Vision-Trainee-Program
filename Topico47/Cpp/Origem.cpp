#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void central_moments(Mat img);

FILE *arquivo;

int main(void) {

	Mat img;
	Mat img_gray;

	arquivo = fopen("central_moments.txt", "w");

	img = imread("image.jpg", 1);
	cvtColor(img, img_gray, CV_BGR2GRAY);
	central_moments(img_gray);

	fclose(arquivo);
}

void central_moments(Mat img) {
	Mat img_Canny;
	Mat img_aux;
	vector<vector<Point>> contours;

	Canny(img, img_Canny, 127, 255, 3);
	Laplacian(img_Canny, img_aux, CV_8UC1, 3);
	threshold(img_aux, img_aux, 127, 255, CV_THRESH_BINARY);
	findContours(img_aux, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	vector<Moments> m(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		m[i] = moments(contours[i], false);
		cout << "Contours: m02 = " << m[i].m02 << endl;
		cout << "	  m03 = " << m[i].m03 << endl;
		cout << "	  m11 = " << m[i].m11 << endl;
		cout << "	  m12 = " << m[i].m12 << endl;
		cout << "     m20 = " << m[i].m20 << endl;
		cout << "	  m21 = " << m[i].m21 << endl;
		cout << "	  m30 = " << m[i].m30 << endl << endl;

		fprintf(arquivo, "Contour %d:\nm02 = %f\nm03 = %f\nm11 = %f\nm12 = %f\nm20 = %f\nm21 = %f\nm30 = %f\n\n\n", i,
			m[i].m02, m[i].m03, m[i].m11, m[i].m12, m[i].m20, m[i].m21, m[i].m30);
	}

}