#ifndef _PARTY_H
#define _PARTY_H

#include <string>
#include <vector>
#include "partymember.h"

class Party {
public:
	Party();
	~Party();

	//void setMember(int m, PartyMember* c) {member[m] = c;}
	void addMember(PartyMember* c);
	void removeMember(const PartyMember* c);
	void removeMember(unsigned int id);
	PartyMember* getMember(unsigned int m);
	unsigned int getMemberCount() const {return member.size();}
	
	unsigned int getEquipQuantity(unsigned int id) const;
	unsigned int getEquipQuantity(std::string name) const;
	void addEquipQuantity(unsigned int id, int count);
	void addEquipQuantity(std::string name, int count);
	void setEquipQuantity(unsigned int id, int q);
	void setEquipQuantity(std::string name, int q);

protected:
private:
	//PartyMember* member[MEMBER_COUNT];
	std::vector<PartyMember*> member;
	std::vector<unsigned int> equipList;

};

#endif
