#include<iostream>
using namespace std;
#ifndef _TILES_
#define _TILES_
#include "rect.h"

//Bit offsets for tile data
const unsigned int TILE_INDEX_OFFSET = 0;
const unsigned int TILE_INDEX_SIZE = 8;		//Held in unsigned char
const unsigned int TILE_ORIENT_OFFSET = 8;
const unsigned int TILE_ORIENT_SIZE = 3;	//Held in TileOrient

enum TileOrient {
	TILE_ORIENT_NORMAL,
	TILE_ORIENT_ROT_90,
	TILE_ORIENT_ROT_180,
	TILE_ORIENT_ROT_270,
	TILE_ORIENT_FLIP_H,
	TILE_ORIENT_FLIP_V,
	TILE_ORIENT_FH_90,
	TILE_ORIENT_FH_270,
	TILE_ORIENT_MAX
};

enum TileReorient {
	TILE_REORIENT_COUNTER,
	TILE_REORIENT_CLOCK,
	TILE_REORIENT_FLIP_H,
	TILE_REORIENT_FLIP_V,
	TILE_REORIENT_MAX
};

extern const TileOrient tileOrientLut[TILE_ORIENT_MAX][TILE_REORIENT_MAX];
class Tilesheet {
	static const int TILESHEET_WIDTH = 16, TILESHEET_HEIGHT = 16, TILESHEET_SIZE = 256, TILEWIDTH = 32, TILEHEIGHT = 32;
	int texture;
	Rect tileRegion[TILESHEET_SIZE];
	
 public:
	Tilesheet(std::string);
	Tilesheet(int texture);
	int getTexture() const;
	Rect getTileRegion(unsigned char) const;
	Rect getTileRegion(int, int) const;
	
	void tileAdvData(unsigned short int id, unsigned char& index, TileOrient& orient) const;
	void tileOffset(unsigned char index, unsigned int& xoffset, unsigned int& yoffset) const;

};

#endif // _TILES
