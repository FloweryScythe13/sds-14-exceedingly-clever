#include <iostream>
#include "stats.h"

const int MAX_STAT_VAL[STAT_MAX] = {
	1000,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100
};

const int PRIM_STAT_COUNT = 4;

const int PRIM_STAT_SCALE[PRIM_STAT_COUNT] = {
	20, 1, 1, 1
};

const int PRIM_STAT_LVL_COST[20] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
};

const std::string STAT_NAME[STAT_MAX] = {
	"HP",
	"Strength",
	"Magic",
	"Speed",
	"Attack",
	"M. Power",
	"P. Defense",
	"I. Defense",
	"M. Defense",
	"Critical",
	"Evasion"
};

StatList::StatList(std::ifstream& file) {
	for(int i = 0; i < STAT_MAX; ++i)
		file >> val[i];
}

StatList::StatList(int hp, int str, int mag, int spd, int atk, int mpow, 
		 int pdef, int idef, int mdef, int crit, int eva) {
    val[0] = hp; 
    val[1] = str; 
    val[2] = mag; 
    val[3] = spd; 
    val[4] = atk; 
    val[5] = mpow; 
    val[6] = pdef; 
    val[7] = idef;
    val[8] = mdef;
    val[9] = crit;
    val[10] = eva;
}

void StatList::print() const {
	for(int i = 0; i < STAT_MAX; ++i) {
		std::cout << val[i] << '\t';
	}
	std::cout << '\n';
}

StatList StatList::operator+ (const StatList& s) {
	StatList temp;
	for(int i = 0; i < STAT_MAX; ++i) {
		temp.val[i] = val[i] + s.val[i];
	}
	
	return temp;
}

StatList StatList::operator* (const StatList& s) {
	StatList temp;
	for(int i = 0; i < STAT_MAX; ++i) {
		temp.val[i] = val[i] * s.val[i];
	}
	
	return temp;
}

void StatList::operator+= (const StatList& s) {
	for(int i = 0; i < STAT_MAX; ++i) {
		val[i] += s.val[i];
	}
}

void StatList::zeroes() {
	for(int i = 0; i < STAT_MAX; ++i) val[i] = 0.0f;
}

void StatList::ones() {
	for(int i = 0; i < STAT_MAX; ++i) val[i] = 1.0f;
}