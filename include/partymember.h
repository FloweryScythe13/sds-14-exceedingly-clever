#ifndef _PARTYMEMBER_H
#define _PARTYMEMBER_H

#include "character.h"

class PartyMember : public Character {
public:
	PartyMember(std::string filename);
	PartyMember(std::ifstream& file);
	~PartyMember();

protected:
private:

};

#endif
