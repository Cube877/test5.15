// test5.15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("gtest.jpg", 0);
	Mat dst = srcMat.clone();
	int height = srcMat.rows;
	int width = srcMat.cols;
	uchar Lut[256];
	float k = 1/2.2;
	for (int i = 0; i < 256; i++)
	{
		/*float f = (float)i / 255;
		f = pow(f, k);
		Lut[i] = f * 255;*/
		Lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0f), k)*255.0f);
	}
	for(int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			dst.at<uchar>(i, j) = Lut[srcMat.at<uchar>(i, j)];
		}
	}
	imshow("gamma矫正", dst);
	//以上为1、3题，以下为2题
	Mat srcMat2 = imread("lena.jpg");
	Mat dst2;
	vector<Mat> channels;
	split(srcMat2, channels);
	Mat B = channels.at(0);
	Mat G = channels.at(1);
	Mat R = channels.at(2);
	equalizeHist(B, B);
	equalizeHist(G, G);
	equalizeHist(R, R);
	merge(channels, dst2);
	imshow("原图", srcMat2);
	imshow("3通道图像直方图均衡", dst2);
	waitKey(0);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
