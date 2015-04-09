#pragma once

#include "Position.h"
#include "Personnage.h"


class CItem
{
protected:

	CItem(CPosition pos, char symbole, unsigned short duree, unsigned short bonus);
	CItem(short x, short y, char symbole, unsigned short duree, unsigned short bonus);
	CItem(CPosition pos, char symbole);
	CItem(short x, short y, char symbole);

public:

	CPosition GetPosItem() const;
	void SetPosItem(CPosition pos);

	char GetSymbole() const;	
	unsigned short GetDuree() const;
	unsigned short GetBonus() const;

	bool operator==(CItem const& a); 

	virtual void UtiliserItem(CPersonnage &perso) = 0;

private:
	CPosition pos_item_;
	char symbole_;
	unsigned short duree_;
	unsigned short bonus_;
};

#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &os, const CItem &it);