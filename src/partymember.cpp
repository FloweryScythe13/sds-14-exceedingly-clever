#include <iostream>
#include "partymember.h"
#include "render.h"

PartyMember::PartyMember(std::string filename) {
	std::ifstream file(filename);
	if(!file.is_open()) return;
	Character::readFromFile(file);
	file.close();
	
	updateEffStats();
}

PartyMember::PartyMember(std::ifstream& file) : Character(file) {
	updateEffStats();
}

PartyMember::~PartyMember() {}
