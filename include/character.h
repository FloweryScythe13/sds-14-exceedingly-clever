#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "battlecmd.h"
#include "equipment.h"
#include "stats.h"
#include "animation.h"

class Character {
public:
	Character();
	Character(std::string name);
	Character(std::ifstream& file);
	virtual ~Character();

	void readFromFile(std::ifstream& file);
	//Getting and setting character statistics
	std::string getName() const {return name;}
	void setName(std::string n) {name = n;}

	int getStatBase(unsigned int i) {return statBase[i];}
	int getStatRaise(unsigned int i) {return statRaise[i];}
	int getStatBonus(unsigned int i) {return statBonus[i];}
	float getStatMod(unsigned int i) {return statMod[i];}
	int getStatEff(unsigned int i) {return statEff[i];}
	
	void updateEffStats();
	
	//void setStatRaise(unsigned int index, int j) {statRaise[index] = j;}
	void setLevel(unsigned int val) {level = val;}
	unsigned int getLevel() const {return level;}

	//Getters and setters for Experience points
	void addTotalExp(unsigned int val) {totalExp += val;}
	void setTotalExp(unsigned int val) {totalExp = val;}
	unsigned int getTotalExp() const {return totalExp;}

	void addFreeExp(unsigned int val) {freeExp += val;}
	void subFreeExp(unsigned int val) {freeExp -= val;}
	void setFreeExp(unsigned int val) {freeExp = val;}
	unsigned int getFreeExp() const {return freeExp;}

	void equipItem(SlotType, unsigned int);
	void equipItem(SlotType, std::string);
	unsigned int getEquipID(SlotType s);
	Equipment getEquipment(SlotType s);

	int getExploreTex() const {return exploreTex;}
	int getFaceTex() const {return faceTex;}
	int getPortraitTex() const {return portraitTex;}
	void setExploreTex(int t) {exploreTex = t;}
	void setFaceTex(int t) {faceTex = t;}
	void setPortraitTex(int t) {portraitTex = t;}

	BattleCommand getBattleCommand(int i) {return commands[i];}
	unsigned int getCommandCount() const {return commands.size();}
	void addBattleCommand(BattleCommand cmd) {commands.push_back(cmd);}

	void print() const;

	void loadAnimation(std::ifstream& file);
	void setAnimation(std::string name);
	Animation* getAnimation() const {return currentAnimation;}
	
	void updateAnimation();
	Rect getAnimationRect() const;

protected:
	std::string name;

	unsigned int level;
	unsigned int totalExp;
	unsigned int freeExp;

	StatList statBase;
	int statRaise[4];
	StatList statBonus;
	StatList statMod;
	StatList statEff;

	//Abilities
	//Inventory
	
	//EquipSlot slot[SLOT_MAX];//0=weapon, 1=head, 2=torso, 3=legs, 4-6=acc
	unsigned int slot[SLOT_MAX];

	//Combat
	std::vector<BattleCommand> commands;

	int exploreTex, faceTex, portraitTex;
	std::map<std::string, Animation> animations;
	Animation* currentAnimation;
	
private:
	void init();
};

#endif
