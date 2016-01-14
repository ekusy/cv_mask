#include "cvFunc.h"


cvFunc::cvFunc()
{
	source = cvLoadImage("./source/test.png");
	min.setColor(HSV, 0, 130, 100);
	max.setColor(HSV, 10, 255, 140);
}

cvFunc::~cvFunc()
{
}

Position cvFunc::getPosition(Mat _source){
	Position pos;
	int count = 0;
	Mat image;
	Mat mask(image.rows, image.cols, CV_8UC3);
	image = _source;

	cvtColor(image, image, CV_BGR2HSV);
	for (int row = 0; row < image.rows; row++){
		for (int col = 0; col < image.cols; col++){
			int num = image.step*row + col*image.channels();
			color source(HSV,image.data[num], image.data[num + 1], image.data[num + 2]);
			if (judgeColor(source, max, min)){
				mask.data[num] = 255;
				mask.data[num+1] = 0;
				mask.data[num+2] = 0;
				pos.x += col;
				pos.y += row;
				count++;
			}
		}
	}
	pos.x /= count;
	pos.y /= count;

	return pos;
}
Position cvFunc::getPosition(Mat _source, double _sX, double _sY){
	Mat image;
	Position pos;
	resize(_source, image, Size(), _sX, _sY);
	pos = getPosition(image);
	pos.x /= _sX;
	pos.y /= _sY;
	return pos;
}
bool cvFunc::judge(int source, int min, int max) {
	if (min == max)
		return true;
	if (min > max) {
		if (source >= max || source <= min)
			return true;
	}
	else {
		if (source >= min && source <= max)
			return true;
	}
	return false;
}
bool cvFunc::judgeColor(color _source, int h_min, int h_max, int s_min, int s_max, int v_min, int v_max) {
	int count = 0;
	if (judge(_source.H, h_min, h_max))
		count++;
	if (judge(_source.S, s_min, s_max))
		count++;
	if (judge(_source.V, v_min, v_max))
		count++;

	if (count == 3)
		return true;
	else
		return false;
}
bool cvFunc::judgeColor(color _source, color _thresholdMax, color _thresholdMin){
	return judgeColor(_source, _thresholdMin.H, _thresholdMax.H, _thresholdMin.S, _thresholdMax.S, _thresholdMin.V, _thresholdMax.V);
}