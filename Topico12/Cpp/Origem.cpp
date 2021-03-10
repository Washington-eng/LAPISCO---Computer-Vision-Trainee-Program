#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	FILE* arquivo;
	char line[1000];
	int linhas=0;
	int colunas = 0;
	char a;
	int valor_mat;
	int i, j;

	arquivo = fopen("arquivo_matriz.txt", "r");
	while (!feof(arquivo)) {
		fgets(line, 1000, arquivo);
		linhas++;
	}
	linhas = linhas - 1;
	fclose(arquivo);

	arquivo = fopen("arquivo_matriz.txt", "r");
	while (!feof(arquivo)) {
		a=fgetc(arquivo);
		if (a == '\t') {
			colunas++;
		}
	}
	colunas = (colunas) / linhas;
	fclose(arquivo);


	arquivo = fopen("arquivo_matriz.txt", "r");
	Mat_<uchar> img(linhas, colunas, 1);

	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			fscanf(arquivo, "%d", &valor_mat);
			img.at<uchar>(i, j) = valor_mat;
		}
	}

	imwrite("img_teste.png", img);
	imshow("Tste0", img);
	fclose(arquivo);
	
	
	waitKey(0);
}