#pragma once

#include "Position.h"

class CItem
{
public:
	CItem();
	CItem(CPosition pos, char symbole, unsigned short duree);
	CItem(short x, short y, char symbole, unsigned short duree);

	CPosition GetPosItem() const;
	void SetPosItem(CPosition pos);

	bool GetIsActive() const;
	void Activate();
	void Disable();

	short GetDuree();

	char GetSymbole() const;
	
	bool operator==(CItem const& a); 

private:
	CPosition pos_item_;
	bool is_active_;
	unsigned short duree_;
	char symbole_;
};

#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &os, const CItem &it);