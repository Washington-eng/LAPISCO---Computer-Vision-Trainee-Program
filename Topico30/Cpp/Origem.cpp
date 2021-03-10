#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void) {
	Mat img;
	Mat img_gray;
	Mat img_Canny;

	vector<vector<Point>> contours;


	img = imread("image.jpg", 1);

	cvtColor(img, img_gray, CV_BGR2GRAY);

	Canny(img_gray, img_Canny, 100, 255);
	
	findContours(img_Canny, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	cout << "Contours number: " << contours.size() << endl;
	imshow("Canny", img_Canny);
	imshow("Input Image", img);
	waitKey(0);
}