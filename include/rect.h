#ifndef _RECT_H
#define _RECT_H

struct Rect {
	Rect(float x = 0, float y = 0, float w = 0, float h = 0);
	float x, y, w, h;
	
	float getCenterX() const;
	float getCenterY() const;
	
	void setCenter(float cx, float cy);
};

#endif
