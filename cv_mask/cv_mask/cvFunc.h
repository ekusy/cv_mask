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
public:
	cvFunc();
	~cvFunc();

	Position getPosition(Mat _source);
	Position getPosition(Mat _source,double _sX,double _sY);
	bool judge(int source, int min, int max);
	bool judgeColor(color _source, int h_min, int h_max, int s_min, int s_max, int v_min, int v_max);
	bool judgeColor(color _source, color _thresholdMax, color _thresholdMin);
};

