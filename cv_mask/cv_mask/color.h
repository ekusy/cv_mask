#pragma once
#define R color1
#define G color2
#define B color3

#define H color1
#define S color2
#define V color3

#define RGB 1
#define HSV 2

class color
{
private:
public:
	unsigned char color1, color2, color3;
	unsigned char colorMode;

	color();
	color(unsigned char _mode);
	color(unsigned char _mode, unsigned char color1, unsigned char  color2, unsigned char  color3);
	~color();
	void init();
	bool setColorMode(unsigned char _colorMode);
	void setColorR(unsigned char _color);
	void setColorB(unsigned char _color);
	void setColorG(unsigned char _color);
	void setColorH(unsigned char _color);
	void setColorS(unsigned char _color);
	void setColorV(unsigned char _color);
	void setColor(unsigned char color1, unsigned char  color2, unsigned char  color3);
	bool setColor(unsigned char _mode, unsigned char color1, unsigned char  color2, unsigned char  color3);

};

