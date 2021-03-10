#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void) {
	Mat img;
	Mat img_gray;
	Mat img_Canny;
	char ObjectName[100];

	vector<vector<Point>> contours;


	//Step 1 
	img = imread("image.jpg", 1);

	cvtColor(img, img_gray, CV_BGR2GRAY);

	Canny(img_gray, img_Canny, 100, 255);

	findContours(img_Canny, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);


	//Step 2
	vector<vector<Point>> contours_poly(contours.size());
	vector<double> Object_area(contours.size());
	vector<Rect> Object_box(contours.size());
	vector<Mat> img_aux(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		approxPolyDP(Mat(contours[i]), contours_poly[i], 1, true);
		Object_box[i] = boundingRect(contours_poly[i]);
		Object_area[i] = contourArea(contours_poly[i], false);
		cout << " Object " << i << ": " << Object_box[i] << "\n" << "  	area = " << Object_area[i] << endl;
	}

	cvtColor(img_Canny, img_Canny, CV_GRAY2BGR);

	for (int i = 0; i < contours.size(); i++) {
		rectangle(img_Canny, Object_box[i], Scalar(0, 0, 255), 3);

		Rect region = Object_box[i];
		img_aux[i] = img_Canny(region);
		sprintf(ObjectName, "Objeto %d", i);

		imshow(ObjectName, img_aux[i]);
		waitKey(1000);

	}

	destroyAllWindows();

	imshow("Output Image", img_Canny);
	imshow("Input Image", img);

	img.release();
	img_gray.release();
	img_Canny.release();
	
	waitKey(0);
}
