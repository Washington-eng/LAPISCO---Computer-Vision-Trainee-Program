#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	Mat img;
	Mat img_gray;

	vector<Vec3f> circles;
	
	img = imread("image.jpg", 1);

	cvtColor(img, img_gray, CV_BGR2GRAY);

	//Laplacian(img_gray, img_gray, CV_8UC1,1);
	GaussianBlur(img_gray, img_gray, Size(5, 5), 3);

	HoughCircles(img_gray, circles, CV_HOUGH_GRADIENT, 1,20,100, 40);

	for (int i = 0; i < circles.size(); i++) {
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		circle(img, center, 2, Scalar(255, 255, 0),2);	//Center point of the circle
		circle(img, center, radius, Scalar(0, 0, 255),3);	//Boundary of the circle

	}

	imshow("Gray Image", img_gray);
	imshow("Original Imagem - Circle identified", img);
	waitKey(0);
	
}