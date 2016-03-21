#include "battlecmd.h"

BattleCommand::BattleCommand(const BattleCommand& b) :
	name(b.name), type(b.type), baseDamage(b.baseDamage),
	cost(b.cost), delay(b.delay) {}
