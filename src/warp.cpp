#include "warp.h"

Warp::Warp(std::ifstream& file) {
	file >> targetCell;
	file >> targetX;
	file >> targetY;
}