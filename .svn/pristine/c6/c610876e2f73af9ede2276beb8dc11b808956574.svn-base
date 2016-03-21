#include <iostream>
#include "combatchar.h"
#include "battlecmd.h"

CombatChar::CombatChar(const Character& character) : Character(character),
	atb(0) {

	currentHP = getStatEff(STAT_HP);
}

void CombatChar::updateATB() {
	atb += 3 + statEff[STAT_SPD] * statEff[STAT_SPD] / 100;
	if(atb >= 100) atb = 100;
	if(atb < 0) atb = 0;
}

void CombatChar::addCurrentHP(int val) {
	currentHP += val;
	if(currentHP > statEff[STAT_HP]) currentHP = statEff[STAT_HP];
	if(currentHP < 0) currentHP = 0;
}

bool CombatChar::performCommand(unsigned int cmd, CombatChar* target,
	int* damageVal) {
	if(cmd >= commands.size() || cmd < 0 || !target) return false;
	if(atb < commands[cmd].cost) return false;
	updateEffStats();

	int damage = 0;
	switch(commands[cmd].type) {
	case CMD_ATK_MELEE:
		damage = (commands[cmd].baseDamage + statEff[STAT_ATK] * 0.75f + statEff[STAT_STR] * 0.5f)
			* (256.0f / (256.0f + target->getStatEff(STAT_IDEF)));
		break;
	case CMD_ATK_PROJECTILE:
		damage = (commands[cmd].baseDamage + statEff[STAT_ATK] * 0.75f + statEff[STAT_STR] * 0.5f)
			* (256.0f / (256.0f + target->getStatEff(STAT_PDEF)))
			+ 0.5 * (target->getStatEff(STAT_HP) - target->getCurrentHP());
		break;
	case CMD_ATK_MAGIC:
		damage = (commands[cmd].baseDamage + statEff[STAT_MPOW] * 1.0f + statEff[STAT_MAG] * 0.5f)
			* (256.0f / (256.0f + target->getStatEff(STAT_MDEF)));
		break;
	default:
		break;
	}

	target->addCurrentHP(-damage);
	atb -= commands[cmd].cost;

	if(damageVal) *damageVal = damage;
	return true;
}
