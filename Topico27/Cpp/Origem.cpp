#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void random_color(int &r, int &g, int &b, int cont);
void frame(int &i_max, int &i_min, int &j_max, int &j_min,int i,int j);

int main(void) {
	Mat img;
	Mat img_gray;
	Mat img_region;
	Mat img_region_aux;
	Mat img_object;

	int filled = 1;
	int filled_final = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	int cont = 0;
	int i_object = 0, j_object = 0;
	int i_max, i_min, j_max, j_min;
	char ImageName[25];
	//int cont_aux = 0;

	img = imread("formas.jpg", 1);
	img_region = Mat(img.rows, img.cols, CV_8UC3);
	img_region_aux = Mat(img.rows, img.cols, CV_8UC1);
	

	cvtColor(img, img_gray, CV_BGR2GRAY);

	for (int i = 0; i < img_gray.rows; i++) {
		for (int j = 0; j < img_gray.cols; j++) {
			img_region_aux.at<uchar>(i, j) = 0;

			img_region.at<Vec3b>(i, j)[0] = 0;
			img_region.at<Vec3b>(i, j)[1] = 0;
			img_region.at<Vec3b>(i, j)[2] = 0;
		}
	}

	for (int i = 0; i < img_gray.rows; i++) {
		for (int j = 0; j < img_gray.cols; j++) {
			if (img_gray.at<uchar>(i, j) == 0 && img_region_aux.at<uchar>(i, j) == 0) {
				img_region_aux.at<uchar>(i, j) = 255;
				cont++;
				random_color(r, g, b, cont);

				//imshow("gray", img_region_aux);
				//waitKey(0);
				i_max = i;
				i_min = i;
				j_max = j;
				j_min = j;

				filled = 1;
				filled_final = 0;

				while (filled != filled_final) {
					filled_final = filled;
					//filled = 0;
					for (int r = 0; r < img_gray.rows; r++) {
						for (int c = 0; c < img_gray.cols; c++) {

							if (img_region_aux.at<uchar>(r, c) == 255) {

								for (int x = -1; x <= 1; x++) {
									for (int y = -1; y <= 1; y++) {

										if (img_gray.at<uchar>(r + x, c + y) < 100 && img_region_aux.at<uchar>(r + x, c + y) != 255) {
											img_region_aux.at<uchar>(r + x, c + y) = 255;
											
											img_region.at<Vec3b>(r + x, c + y)[0] = b;
											img_region.at<Vec3b>(r + x, c + y)[1] = g;
											img_region.at<Vec3b>(r + x, c + y)[2] = r;
											frame(i_max, i_min, j_max, j_min, r + x, c + y);

											filled++;
										}


									}
								}
							}
						}
					}

					imshow("Aux Region", img_region_aux);
					imshow("Final region", img_region);
					waitKey(10);
				}
			
				img_object = Mat(i_max - i_min, j_max - j_min, CV_8UC3);

				for (int i = 0; i < img_object.rows; i++) {
					for (int j = 0; j < img_object.cols; j++) {
						img_object.at<Vec3b>(i, j)[0] = 0;
						img_object.at<Vec3b>(i, j)[1] = 0;
						img_object.at<Vec3b>(i, j)[2] = 0;
					}
				}

				i_object = 0;

				for (int i = i_min; i < i_max; i++) {
					j_object = 0;
					for (int j = j_min; j < j_max; j++) {
						img_object.at<Vec3b>(i_object, j_object)[0] = img_region.at<Vec3b>(i, j)[0];
						img_object.at<Vec3b>(i_object, j_object)[1] = img_region.at<Vec3b>(i, j)[1];
						img_object.at<Vec3b>(i_object, j_object)[2] = img_region.at<Vec3b>(i, j)[2];
						j_object++;
					}
					i_object++;
				}
				sprintf(ImageName, "Object%d.png", cont);
				imwrite(ImageName, img_object);
				imshow(ImageName, img_object);
			}
			
			
		}
	}
	destroyWindow("Aux Region");
	destroyWindow("Final region");

	waitKey(0);


}

void random_color(int &r, int &g, int &b, int cont) {

	srand((unsigned)time(NULL));
	/*
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;*/
	if (cont == 0) {

		r *= rand() % 256;
		g -= rand() % 256;
		b += rand() % 256;
	}
	else if (cont % 2 != 0) {

		r -= rand() % 256;
		g *= rand() % 256;
		b += rand() % 256;
	}
	else if (cont % 2 == 0) {

		r += rand() % 256;
		g -= rand() % 256;
		b *= rand() % 256;
	}
}

void frame(int &i_max, int &i_min, int &j_max, int &j_min, int i, int j) {
		
	if (i > i_max) {
		i_max = i;
	}
	else if (i < i_min) {
		i_min = i;
	}

	if (j > j_max) {
		j_max = j;
	}
	else if (j < j_min) {
		j_min = j;
	}
}