#ifndef _STATS_H
#define _STATS_H

#include <fstream>
#include <string>

enum StatType {
	STAT_HP,
	STAT_STR,
	STAT_MAG,
	STAT_SPD,
	STAT_ATK,
	STAT_MPOW,
	STAT_PDEF,
	STAT_IDEF,
	STAT_MDEF,
	STAT_CRIT,
	STAT_EVA,
	STAT_MAX
};

extern const int MAX_STAT_VAL[];	//Highest value for every stat
extern const int PRIM_STAT_COUNT;	//HP, Strength, Magic, Speed
extern const int PRIM_STAT_SCALE[];	//Value of each raised point
extern const int PRIM_STAT_LVL_COST[];	//Exp cost per raised point
extern const std::string STAT_NAME[];

struct StatList {
	float val[STAT_MAX];
	StatList(std::ifstream& file);
    StatList(int hp = 0, int str = 0, int mag = 0, int spd = 0, int atk = 0, int mpow = 0, 
		 int pdef = 0, int idef = 0, int mdef = 0, int crit = 0, int eva = 0);
		 
	float& operator[] (int i) {return val[i];}
	StatList operator+ (const StatList&);
	StatList operator* (const StatList&);
	
	void operator+= (const StatList&);
	
	void zeroes();
	void ones();
	
	void print() const;
};

#endif
