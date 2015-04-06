#pragma once

#include "Position.h"
#include "Personnage.h"

class CItem
{
protected:

	CItem(CPosition pos, char symbole);
	CItem(short x, short y, char symbole);

public:

	CPosition GetPosItem() const;
	void SetPosItem(CPosition pos);

	bool GetIsActive() const;
	void Activate();
	void Disable();

	char GetSymbole() const;
	
	bool operator==(CItem const& a); 

	virtual void UseItem(CPersonnage &perso) {};

private:
	CPosition pos_item_;
	bool is_active_;
	char symbole_;
};

#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &os, const CItem &it);