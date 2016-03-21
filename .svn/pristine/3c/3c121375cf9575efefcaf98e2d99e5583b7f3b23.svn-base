#ifndef _IMAGEBOX_H
#define _IMAGEBOX_H

#include "widget.h"

class ImageBox : public Widget {
public:
	ImageBox(int tex, const Rect& pos, float z = 0.0f, Widget* parent = 0);
	virtual ~ImageBox();

	virtual void draw();
	
	int getTexture() const {return texture;}
	void setTexture(int t) {texture = t;}

protected:
	int texture;
	
private:

};

#endif
