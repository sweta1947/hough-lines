#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat var1 = imread("hof.jpg", 1);
	Mat var2, var3, var4;

	cvtColor(var1, var2, CV_RGB2GRAY);

	blur(var2, var3, Size(3, 3));

	Canny(var3, var4, 50, 100);

	vector<Vec2f> lines;

	HoughLines(var4, lines, 1, CV_PI / 180.f, 100);
	// Draw lines
	Mat img_show = var1.clone();
	for (int i = 0; i < lines.size(); i++) {
		float rho = lines[i][0];
		float theta = lines[i][1];
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		Point pt1(cvRound(x0 + 1000 * (-b)), cvRound(y0 + 1000 * (a)));
		Point pt2(cvRound(x0 - 1000 * (-b)), cvRound(y0 - 1000 * (a)));
		line(img_show, pt1, pt2, Scalar(0, 0, 255));
	}

	namedWindow("window1", WINDOW_AUTOSIZE);
	imshow("Shapes", img_show);







	waitKey(0);
	return 0;

}