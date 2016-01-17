#pragma once

#define RGB_MODE 1
#define HSV_MODE 2
class color
{
private:
	unsigned char color1, color2, color3;
	unsigned char colorMode; 
public:


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
	color getColor(void);
	unsigned char getColorMode(void);
	unsigned char getColorR(void);
	unsigned char getColorG(void);
	unsigned char getColorB(void);
	unsigned char getColorH(void);
	unsigned char getColorS(void);
	unsigned char getColorV(void);
};

