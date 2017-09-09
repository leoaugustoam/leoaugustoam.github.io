#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image(256,256,CV_8UC1);
  Mat image2(256,256,CV_8UC1);
  image= imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data){
	  cout << "A imagem nao abriu" << endl;
  }
 //namedWindow("janela",WINDOW_AUTOSIZE);
  Mat quadrado1(image, Rect(0,0,128,128));
  Mat quadrado2(image, Rect(128,0,128,128));
  Mat quadrado3(image, Rect(0,128,128,128));
  Mat quadrado4(image, Rect(128,128,128,128));

  quadrado1.copyTo(image2(Rect(128, 128, 128, 128)));
  quadrado2.copyTo(image2(Rect(128, 0, 128, 128)));
  quadrado3.copyTo(image2(Rect(0, 128, 128, 128)));
  quadrado4.copyTo(image2(Rect(0, 0, 128, 128)));

  imshow("Trab2", image2);
  imwrite("bieltrocado.png", image2);
  waitKey();
return 0;
}
