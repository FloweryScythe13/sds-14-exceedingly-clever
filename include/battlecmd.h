#ifndef _BATTLECMD_H
#define _BATTLECMD_H

#include <string>

enum CmdType {
	CMD_ATK_MELEE,
	CMD_ATK_PROJECTILE,
	CMD_ATK_MAGIC,
	CMD_MAX
};

struct BattleCommand {
	BattleCommand() {}
	BattleCommand(std::string n, CmdType t, int base,
		int cost, int delay) : name(n), type(t), baseDamage(base),
		cost(cost), delay(delay) {}
	BattleCommand(const BattleCommand& b);
	std::string name;
	CmdType type;
	int baseDamage;
	int cost;
	int delay;
};

#endif
