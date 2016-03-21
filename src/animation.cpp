#include <iostream>
#include <fstream>
#include "animation.h"

Animation::Animation() {}
Animation::Animation(std::ifstream& file) : counter(0), frameIndex(0), frameAdv(1),
	paused(0) {
	file >> name;
	file >> framew;
	file >> frameh;
	file >> framerows;
	file >> framecolumns;
	file >> oscillate;
	file >> framedur;
	
	unsigned int frameCount;
	file >> frameCount;

	for(unsigned int i = 0; i < frameCount; ++i) {
		unsigned int temp;
		file >> temp;
		frames.push_back(temp);
	}
}

Rect Animation::getFrameRect() const {
	int frameNum = frames[frameIndex];
	int xcoord = frameNum % framecolumns;
	int ycoord = frameNum / framecolumns;
	return Rect(xcoord * framew, ycoord * frameh, framew, frameh);
}

void Animation::update() {
	if(!paused && ++counter > framedur) {
		counter = 0;
		if(oscillate && frameIndex == frames.size() - 1)
			frameAdv = -1;
		if(oscillate && frameIndex == 0)
			frameAdv = 1;
		if(!oscillate && frameIndex == frames.size() - 1) {
			pause();
			return;
		}

		frameIndex += frameAdv;
	}
}
