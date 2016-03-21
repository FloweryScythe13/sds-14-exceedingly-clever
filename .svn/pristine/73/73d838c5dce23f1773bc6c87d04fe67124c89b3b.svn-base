#include<iostream>
using namespace std;
#include "tiles.h"
#include "render.h"

const TileOrient tileOrientLut[TILE_ORIENT_MAX][TILE_REORIENT_MAX] = {
	//Action
	//ROT_COUNTER			ROT_CLOCK				FLIP_H					FLIP_V					//Orient
	{TILE_ORIENT_ROT_90,	TILE_ORIENT_ROT_270,	TILE_ORIENT_FLIP_H,		TILE_ORIENT_FLIP_V	},	//NORMAL
	{TILE_ORIENT_ROT_180,	TILE_ORIENT_NORMAL,		TILE_ORIENT_FH_270,		TILE_ORIENT_FH_90	},	//ROT_90
	{TILE_ORIENT_ROT_270,	TILE_ORIENT_ROT_90,		TILE_ORIENT_FLIP_V,		TILE_ORIENT_FLIP_H	},	//ROT_180
	{TILE_ORIENT_NORMAL,	TILE_ORIENT_ROT_180,	TILE_ORIENT_FH_90,		TILE_ORIENT_FH_270	},	//ROT_270
	{TILE_ORIENT_FH_90,		TILE_ORIENT_FH_270,		TILE_ORIENT_NORMAL,		TILE_ORIENT_ROT_180	},	//FLIP_H
	{TILE_ORIENT_FH_270,	TILE_ORIENT_FH_90,		TILE_ORIENT_ROT_180,	TILE_ORIENT_NORMAL	},	//FLIP_V
	{TILE_ORIENT_FLIP_V,	TILE_ORIENT_FLIP_H,		TILE_ORIENT_ROT_270,	TILE_ORIENT_ROT_90	},	//FH_90
	{TILE_ORIENT_FLIP_H,	TILE_ORIENT_FLIP_V,		TILE_ORIENT_ROT_90,		TILE_ORIENT_ROT_270	}	//FH_270
};

Tilesheet::Tilesheet(std::string input) {
	texture = loadTexture(input.c_str());
	for(int i = 0; i < TILESHEET_SIZE; ++i) {
		int x = TILEWIDTH * (i % TILESHEET_WIDTH);
		int y = TILEHEIGHT * (i / TILESHEET_WIDTH);
		tileRegion[i].x = x;
		tileRegion[i].y = y;
		tileRegion[i].w = TILEWIDTH;
		tileRegion[i].h = TILEHEIGHT;
	}
}

Tilesheet::Tilesheet(int t) {
	texture = t;
	for(int i = 0; i < TILESHEET_SIZE; ++i) {
		int x = TILEWIDTH * (i % TILESHEET_WIDTH);
		int y = TILEHEIGHT * (i / TILESHEET_WIDTH);
		tileRegion[i].x = x;
		tileRegion[i].y = y;
		tileRegion[i].w = TILEWIDTH;
		tileRegion[i].h = TILEHEIGHT;
	}
}

int Tilesheet::getTexture() const {return texture;}

Rect Tilesheet::getTileRegion(unsigned char index) const {
	return tileRegion[index];
}

Rect Tilesheet::getTileRegion(int x, int y) const {
	int index;
	index = y*TILEHEIGHT + x;
	return tileRegion[index];
}

void Tilesheet::tileAdvData(unsigned short int id, unsigned char& index, TileOrient& orient) const {
	index = ((id >> TILE_INDEX_OFFSET) & (TILESHEET_SIZE - 1));
	orient = (TileOrient)((id >> TILE_ORIENT_OFFSET) & (TILE_ORIENT_MAX - 1));
}

void Tilesheet::tileOffset(unsigned char index,
	unsigned int& xoffset, unsigned int& yoffset) const {
	if(index >= TILESHEET_SIZE) return;
	yoffset = TILEHEIGHT * (index / TILESHEET_WIDTH);
	xoffset = TILEWIDTH * (index % TILESHEET_WIDTH);
}