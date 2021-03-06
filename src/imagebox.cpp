#include "imagebox.h"
#include "render.h"

ImageBox::ImageBox(int tex, const Rect& pos, float z, Widget* parent) :
	Widget(pos, z, parent), texture(tex) {}

ImageBox::~ImageBox() {}

void ImageBox::draw() {
	if(!visible) return;
	drawChildren();
	drawTexture(texture, getAbsPos(), z);
}
