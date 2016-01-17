#include "cvFunc.h"
#define COLOR_MACRO

cvFunc::cvFunc()
{
	source = cvLoadImage("./source/sample2.png");
	min.setColor(HSV_MODE, 100, 130, 100);
	max.setColor(HSV_MODE, 110, 255, 140);
}

cvFunc::~cvFunc()
{
}

Position cvFunc::getPosition(){
	return getPosition(source);
}
Position cvFunc::getPosition(double _sX, double _sY){
	return getPosition(source, _sX, _sY);
}
Position cvFunc::getPosition(Mat _sourced){
	Position pos;
	int count = 0;
	Mat image = _source.clone();
	Mat mask(image.rows, image.cols, CV_8UC3);
	mask = Scalar(0, 0, 0);

	cvtColor(image, image, CV_BGR2HSV);
	for (int row = 0; row < image.rows; row++){
		for (int col = 0; col < image.cols; col++){
			int num = image.step*row + col*image.channels();
			color source(HSV_MODE,image.data[num], image.data[num + 1], image.data[num + 2]);
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
	if (count != 0){
		pos.x /= count;
		pos.y /= count;
	}
	else{
		pos.x = -1;
		pos.y = -1;

	}

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
bool cvFunc::judge(unsigned char source, unsigned char min, unsigned char max) {
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
bool cvFunc::judgeColor(color _source, unsigned char h_min, unsigned char h_max, unsigned char s_min, unsigned char s_max, unsigned char v_min, unsigned char v_max) {
	int count = 0;
	if (judge(_source.getColorH(), h_min, h_max))
		count++;
	if (judge(_source.getColorS(), s_min, s_max))
		count++;
	if (judge(_source.getColorV(), v_min, v_max))
		count++;

	if (count == 3)
		return true;
	else
		return false;
}
bool cvFunc::judgeColor(color _source, color _thresholdMax, color _thresholdMin){
	return judgeColor(_source, _thresholdMin.getColorH(), _thresholdMax.getColorH()
		, _thresholdMin.getColorS(), _thresholdMax.getColorS()
		, _thresholdMin.getColorV(), _thresholdMax.getColorV());
}