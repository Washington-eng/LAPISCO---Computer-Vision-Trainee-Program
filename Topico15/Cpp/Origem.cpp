#include"opencv/highgui.h"
#include"opencv2/opencv.hpp"

using namespace cv;

int main() {

	Mat frame;
	Mat frame_gray;

	while (1) {
		VideoCapture capture(0);

		capture >> frame;
		imshow("Camera", frame);
		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		Canny(frame_gray, frame_gray, 50, 200);
		imshow("Camera_Cinza", frame_gray);

		waitKey(100);


	}

}