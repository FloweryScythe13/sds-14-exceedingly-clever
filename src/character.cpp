#include "character.h"
#include "render.h"

void Character::init() {
	//slot[SLOT_WEAPON].type = EQUIP_WEAPON;
	//slot[SLOT_HEAD].type = EQUIP_HEAD;
	//slot[SLOT_TORSO].type = EQUIP_TORSO;
	//slot[SLOT_LEGS].type = EQUIP_LEGS;
	//slot[SLOT_ACC1].type = EQUIP_ACC;
	//slot[SLOT_ACC2].type = EQUIP_ACC;
	//slot[SLOT_ACC3].type = EQUIP_ACC;
	for(int i = 0; i < SLOT_MAX; ++i) {
		slot[i] = emptySlotID[i];
	}

	commands.push_back(BattleCommand("Attack",
		CMD_ATK_MELEE, 20, 30, 20));
	
	updateEffStats();
}

Character::Character() : level(0), totalExp(0), freeExp(0), currentAnimation(0) {
	init();
}

Character::Character(std::string filename) : level(0), totalExp(0), freeExp(0), currentAnimation(0) {
	std::ifstream file(filename);
	if(!file.is_open()) return;
	readFromFile(file);
	file.close();
	init();
}

Character::Character(std::ifstream& file) : currentAnimation(0) {
	if(!file.is_open()) return;
	readFromFile(file);
	init();
}

Character::~Character() {}

void Character::readFromFile(std::ifstream& file) {
	if(!file.is_open()) return;
	file >> name;
	for(int i = 0; i < STAT_MAX; ++i) {
		file >> statBase.val[i];
		statBonus[i] = 0;
		statMod[i] = 0;
		statEff[i] = 0;
	}

	for(int i = 0; i < PRIM_STAT_COUNT; ++i) {
		statRaise[i] = 0;
	}

	std::string temp;
	file >> temp;
	exploreTex = loadTexture(temp.c_str());
	file >> temp;
	faceTex = loadTexture(temp.c_str());
	file >> temp;
	portraitTex = loadTexture(temp.c_str());
	
	loadAnimation(file);
}

void Character::updateEffStats() {
	statBonus.zeroes();
	statMod.ones();
	statEff.zeroes();
	
	for(int i = 0; i < PRIM_STAT_COUNT; ++i) {
		statBonus += statRaise[i];
	}
	
	for(int i = 0; i < SLOT_MAX; ++i) {
		statBonus += getEquipment((SlotType)i).getBonus();
		statMod += getEquipment((SlotType)i).getMods();
	}
	
	statEff = (statBase + statBonus) * statMod;
}

void Character::equipItem(SlotType i, unsigned int gear) {
	//if(slot[i].type != Equipment::equipFromID(gear).getType()) return;
	if(slotEquipType[i] != Equipment::equipFromID(gear).getType()) {
	std::cout << "Attempting to equip an item of type " << 
		equipTypeName[Equipment::equipFromID(gear).getType()] <<
		" into the " << slotName[i] << " slot. Abort!\n";
		return;
	}
	slot[i] = gear;
	updateEffStats();
}

void Character::equipItem(SlotType i, std::string name) {
	equipItem(i, Equipment::idFromName(name));
}

unsigned int Character::getEquipID(SlotType s) {
	return slot[s];
}

Equipment Character::getEquipment(SlotType s) {
	return Equipment::equipFromID(slot[s]);
}

void Character::print() const {
	std::cout << "\nCharacter Information for " << name << "\n\n";
	std::cout << "Level:\t\t" << level << '\n';
	std::cout << "Total Exp:\t" << totalExp << '\n';
	std::cout << "Free Exp:\t" << freeExp << "\n\n";
	
	std::cout << "\nBase Stats:\t\t";
	statBase.print();
	
	std::cout << "Stat Raises:\t\t";
	for(int i = 0; i < PRIM_STAT_COUNT; ++i) {
		std::cout << statRaise[i] << '\t';
	}
	
	std::cout << "\nStat Bonuses:\t\t";
	statBonus.print();
	
	std::cout << "Stat Modifiers:\t\t";
	statMod.print();
	
	std::cout << "Effective Stat:\t\t";
	statEff.print();
	
	std::cout << "\nEquipment\n";
	for(int i = 0; i < SLOT_MAX; ++i) {
		Equipment::equipFromID(slot[i]).print();
	}
}

void Character::setAnimation(std::string name) {
	if(currentAnimation && currentAnimation->getName() == name) return;
	if(animations.find(name) == animations.end()) return;
	currentAnimation = &animations[name];
	currentAnimation->restart();
}

void Character::loadAnimation(std::ifstream& file) {
	unsigned int animCount;
	file >> animCount;
	for(unsigned int i = 0; i < animCount; ++i) {
		Animation temp(file);
		animations[temp.getName()] = temp;
	}
}

void Character::updateAnimation() {
	if(!currentAnimation) return;
	currentAnimation->update();
}

Rect Character::getAnimationRect() const {
	if(!currentAnimation) return Rect(0, 0, 32, 32);
	return currentAnimation->getFrameRect();
}