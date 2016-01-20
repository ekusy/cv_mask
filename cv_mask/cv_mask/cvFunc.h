#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

#include "Position.h"
#include "color.h"

using namespace cv;
class cvFunc
{
private :
	Mat source;
	Mat mask;
	Position pos;
	color max;
	color min;
	VideoCapture cap;
public:
	cvFunc();
	~cvFunc();

	bool setCapture(void);
	void readCapture(void);
	Position getPosition(void);
	Position getPosition(double _sX, double _sY);
	Position getPosition(Mat _source);
	Position getPosition(Mat _source,double _sX,double _sY);
	bool judge(unsigned char source, unsigned char min, unsigned char max);
	bool judgeColor(color _source, unsigned char h_min, unsigned char h_max, unsigned char s_min, unsigned char s_max, unsigned char v_min, unsigned char v_max);
	bool judgeColor(color _source, color _thresholdMax, color _thresholdMin);
};

