#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
	Mat image;
	int width, height;
	int comfuro, semfuro, total;
	CvPoint p;
	image = imread("bolhas.png", CV_LOAD_IMAGE_GRAYSCALE);
	if (!image.data) {
		cout << "Erro ao carregar imagem, pfvr, verificar.\n";
	}
	width = image.size().width;
	height = image.size().height;
	p.x = 0;
	p.y = 0;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (i == 0 || i == 255 || j == 0 || j == 255) {
				if (image.at<uchar>(i, j) != 0) {
					p.x = j;
					p.y = i;
					floodFill(image, p, 0);
				}
			}
		}
	}
	p.x = 0;
	p.y = 0;
	floodFill(image, p, 200);
	comfuro = 0;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (image.at<uchar>(i, j) == 0) {
				if (image.at<uchar>(i, j - 1) == 255) {
					comfuro++;
					p.y = i;
					p.x = j - 1;
					floodFill(image, p, 250);
				}
			}
		}
	}
	semfuro = 0;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (image.at<uchar>(i, j) == 255) {
				semfuro++;
				p.x = j;
				p.y = i;
				floodFill(image, p, 150);
			}
		}
	}
	cout << "Numero de bolhas com buracos:" << comfuro << endl;
	cout << "Numero de bolhas sem buracos:" << semfuro << endl;
	cout << "Numero de bolhas totais:" << (semfuro+comfuro) << endl;
	imshow("image", image);
	imwrite("labeling.png", image);
	waitKey();
	return 0;
} 	
