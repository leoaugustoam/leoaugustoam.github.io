#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int, char**) {
	
	int x1,x2,y1,y2;
	Mat image;
	Size size;
	
	image = cv::imread("biel.png", CV_LOAD_IMAGE_GRAYSCALE);

	if(!image.data){
    		cout << "Imagem não abriu" << endl;
	}

	//imshow("image", image);
	size = image.size();
	
	cout << "Sua imagem tem "<< size.height <<"x" << size.width << endl;
	cout << "Digite os pontos da area que deseja negativar!\nPrimeiro X1:\n";
	cin >> x1;
	cout << "Agora Y1\n";
	cin >> y1;
	cout << "Agora X2\n";
	cin >> x2;
	cout << "Agora Y2\n";
	cin >> y2;

	for(int x=x1; x<=x2; x++) {
		for(int y=y1; y<=y2; y++) {
			image.at<uchar>(x,y)= 255 - image.at<uchar>(x,y);
		}
	}
	//namedWindow("Trab 1",WINDOW_AUTOSIZE);	
	imshow("Trabalho 1", image);
	waitKey();
  
  return 0;
}
