#include "color.h"
#define COLOR_MACRO

color::color()
{
	init();
}

color::color(unsigned char _colorMode){
	init();
	colorMode = _colorMode;
}

color::color(unsigned char _colorMode, unsigned char _color1, unsigned char _color2, unsigned char _color3){
	init(); 
	colorMode = _colorMode;
	color1 = _color1;
	color2 = _color2;
	color3 = _color3;
}

color::~color()
{
}

void color::init(){
	colorMode = RGB_MODE;
	color1 = 0;
	color2 = 0;
	color3 = 0;
}
bool color::setColorMode(unsigned char _colorMode){
	if (_colorMode == RGB_MODE || _colorMode == HSV_MODE){
		colorMode = _colorMode;
		return true;
	}
	else{
		return false;
	}
}
void color::setColorR(unsigned char _color){
	color1 = _color;
}
void color::setColorB(unsigned char _color){
	color2 = _color;
}
void color::setColorG(unsigned char _color){
	color3 = _color;
}
void color::setColorH(unsigned char _color){
	setColorR(_color);
}
void color::setColorS(unsigned char _color){
	setColorG(_color);
}
void color::setColorV(unsigned char _color){
	setColorB(_color);
}
void color::setColor(unsigned char _color1, unsigned char  _color2, unsigned char  _color3){
	setColorR(_color1);
	setColorG(_color2);
	setColorB(_color3);
}
bool color::setColor(unsigned char _mode, unsigned char _color1, unsigned char  _color2, unsigned char  _color3){
	bool flg = setColorMode(_mode);
	if (flg == true){
		setColor(_color1, _color2, _color3);
		return true;
	}
	else
		return false;
}
color color::getColor(void){
	color c(colorMode, color1, color2, color3);
	return c;
}
unsigned char color::getColorMode(void){
	return colorMode;
}
unsigned char color::getColorR(void){
	return color1;
}
unsigned char color::getColorG(void){
	return color2;
}
unsigned char color::getColorB(void){
	return color3;
}
unsigned char color::getColorH(void){
	return getColorR();
}
unsigned char color::getColorS(void){
	return getColorG();
}
unsigned char color::getColorV(void){
	return getColorB();
}

