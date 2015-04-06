#pragma once

#include "Position.h"
#include "Personnage.h"


class CItem
{
protected:

	CItem(CPosition pos, char symbole,unsigned short duree);
	CItem(short x, short y, char symbole, unsigned short duree);
	CItem(CPosition pos, char symbole);
	CItem(short x, short y, char symbole);

public:

	CPosition GetPosItem() const;
	void SetPosItem(CPosition pos);

	char GetSymbole() const;
	
	unsigned short getduree() const;

	bool operator==(CItem const& a); 

	virtual void UseItem(CPersonnage &perso) {};

private:
	CPosition pos_item_;
	char symbole_;
	unsigned short duree_;
};

#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &os, const CItem &it);