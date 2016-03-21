#include "npc.h"

NPC::NPC(string filename) {
  ifstream file(filename);
  if(!file.is_open()) return;
  readFromFile(file);
  int temp;
  file >> temp;
  file.get();
  for(int i = 0; i < temp; i++) {
    string text;
    getline(file,text);
    dialogue.push_back(text);  
  }
  file.close();
  position = Rect(96,96,32,32);
  playerAdjac = 0;
}

NPC::NPC(std::ifstream& file) {
	std::string charInfo;
	file >> charInfo;
	
	std::ifstream charFile(charInfo);
	readFromFile(charFile);
	charFile.close();
	
	file >> tilex;
	file >> tiley;
	
	int lineCount;
	file >> lineCount;
	if(lineCount > 0) {
		file.get();
		for(int i = 0; i < lineCount; ++i) {
			std::string text;
			getline(file, text);
			dialogue.push_back(text);
		}
	}
	
	position = Rect(tilex * 32.0f, tiley * 32.0f, 32.0f, 32.0f);
	playerAdjac = 0;
}