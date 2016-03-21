#ifndef _CELL_
#define _CELL_

#include <string>
#include <vector>

struct Rect;
class Character;
class NPC;
class Tilesheet;
class Warp;
class Cell {
	int width, height;
	static const int CELL_MAX_LAYER = 3, CELL_MAX_WIDTH = 200,
		CELL_MAX_HEIGHT = 200;
		
	unsigned short int tiles[CELL_MAX_LAYER][CELL_MAX_HEIGHT][CELL_MAX_WIDTH];
	int solids[CELL_MAX_HEIGHT][CELL_MAX_WIDTH];
	Tilesheet* ptile;

	std::string directory;
	std::string name;
	
	NPC* npcs[CELL_MAX_HEIGHT][CELL_MAX_WIDTH];
	Warp* warps[CELL_MAX_HEIGHT][CELL_MAX_WIDTH];
	
	std::vector<Character*> battleEnemies;

 public:
	Cell(std::string directory);
	~Cell();

	int getWidth() const {return width;}
	int getHeight() const {return height;}
	
	NPC* getNPC(int tilex, int tiley);
	Warp* getWarp(int tilex, int tiley);
	std::vector<Character*>& getEnemies() {return battleEnemies;}
	int getCollision(int tilex, int tiley) const;
	
	void draw(const Rect& camera) const;

};

#endif
