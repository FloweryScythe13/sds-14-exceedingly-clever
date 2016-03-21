#ifndef _NPC_H
#define _NPC_H
#include <fstream>
#include <iostream>
#include <vector>
#include "rect.h"
#include "character.h"
using namespace std;

class NPC : public Character {
 public:
  NPC(string filename);
  NPC(std::ifstream& file);
  NPC() {}
  
  std::vector<std::string>& getDialogue() {return dialogue;}
  
  Rect getPosition() const {return position;}
  int getTileX() const {return tilex;}
  int getTileY() const {return tiley;}
  void setTileX(int x) {tilex = x;}
  void setTileY(int y) {tiley = y;}
 protected:
  Rect position;
  int tilex, tiley;
  vector<string> dialogue;
  bool playerAdjac;
};


#endif 
