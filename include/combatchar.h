#ifndef _COMBATCHAR_H
#define _COMBATCHAR_H

#include "battlecmd.h"
#include "character.h"

class CombatChar : public Character {
 public:
	CombatChar(const Character& character);
	bool checkATB() const {
		return (atb == 100);
	}
	int getATB() const {return atb;}
	void addATB(int val) {atb += val;}
	void setATB(int val) {atb = val;}

	void updateATB();

	bool performCommand(unsigned int cmd, CombatChar* target,
		int* damageVal = 0);

	void addCurrentHP(int val);
	void setCurrentHP(int val);
	int getCurrentHP() const {return currentHP;}

 protected:
 

 private:
	int atb;
	int currentHP;
};
	


#endif
