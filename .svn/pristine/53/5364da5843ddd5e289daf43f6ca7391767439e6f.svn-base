#include "rect.h"

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

float Rect::getCenterX() const {
	return x + w / 2.0f;
}

float Rect::getCenterY() const {
	return y + h / 2.0f;
}

void Rect::setCenter(float cx, float cy) {
	x = cx - w / 2.0f;
	y = cy - h / 2.0f;
}
