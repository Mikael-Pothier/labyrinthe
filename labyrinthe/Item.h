#include "position.h";
#pragma once

class CItem
{
public:
	CItem(CPosition pos,char Symbole, unsigned short durée);
	CItem(short x, short y, char Symbole,unsigned short durée);

	CPosition GetPosItem() const;
	void SetPosItem(CPosition pos);

	bool GetIsActive() const;
	void Activate();
	void Disable();

	short GetDuree();

	char GetSymbole();
	
	bool operator==(CItem const& a); 

private:
	CPosition positem_;
	bool EstActive_;
	unsigned short Duree_;
	char Symbole_;

};