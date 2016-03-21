#ifndef _EQUIPMENT_
#define _EQUIPMENT_

#include <string>
#include <map>
#include <vector>
#include "stats.h"

enum EquipType{ 
	EQUIP_BLANK 	= 0,
	EQUIP_WEAPON 	= 1,
	EQUIP_HEAD 		= 2,
	EQUIP_TORSO 	= 3,
	EQUIP_LEGS 		= 4,
	EQUIP_ACC 		= 5,
	EQUIP_MAX
};

enum WeaponType{
	WEAP_NONE		= 0,
	WEAP_DAGGER		= 1,
	WEAP_MISSILE	= 2,
	WEAP_SWORD		= 3,
	WEAP_POLELANCE	= 4,
	WEAP_GUN		= 5,
	WEAP_STAFF		= 6,
	WEAP_HAMMER		= 7,
	WEAP_BOOK		= 8,
	WEAP_GRENADE	= 9,
	WEAP_MAX
};

enum SlotType{
	SLOT_WEAPON	= 0,
	SLOT_HEAD	= 1,
	SLOT_TORSO	= 2,
	SLOT_LEGS	= 3,
	SLOT_ACC1	= 4,
	SLOT_ACC2	= 5,
	SLOT_ACC3	= 6,
	SLOT_MAX
};

extern const unsigned int emptySlotID[];
extern const EquipType slotEquipType[];
extern std::string slotName[];
extern std::string equipTypeName[];
extern std::string weaponTypeName[];

class Equipment { 
public:
	Equipment();
	Equipment(std::ifstream& file);
	Equipment(EquipType, WeaponType, std::string, StatList, StatList); 

	EquipType getType() {return type;}
	WeaponType getWeaponType() {return weaptype;}
	std::string getName() {return name;}
	StatList getBonus() {return statBonus;}
	StatList getMods() {return statMod;}
	
	void setType(EquipType i) {type = i;}
	void setWeapType(WeaponType i) {weaptype = i;}
	void setName(std::string namae) {name = namae;}
	void setBonus(StatList bon) {statBonus = bon;}
	void setMod(StatList mds) {statMod = mds;}
	
	void print() const;

	//Static members for a global equipment list
	static void loadEquipmentList(std::string filename);
	static Equipment equipFromID(unsigned int id);
	static unsigned int idFromName(std::string name);
	static Equipment equipFromName(std::string name);
	static unsigned int getEquipCount() {return _equipList.size();}
	static std::vector<unsigned int> getEquipTypeList(EquipType t) {return _sortedEquipList[t];}

protected:

private:
	static std::vector<Equipment> _equipList;
	static std::vector<unsigned int> _sortedEquipList[EQUIP_MAX];
	static std::map<std::string, unsigned int> _equipNameMap;

	EquipType type;
	WeaponType weaptype;
	std::string name;
	StatList statBonus, statMod;
	
};

struct EquipSlot {
	EquipType type;
	unsigned int equip;
	EquipSlot();
	EquipSlot(EquipType, unsigned int);
};



#endif
