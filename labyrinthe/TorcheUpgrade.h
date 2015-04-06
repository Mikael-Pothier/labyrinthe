#pragma once;
#include "Item.h";

class CTorcheUpgrade : public CItem
{
public:
	CTorcheUpgrade(CPosition pos, char symbole);
	CTorcheUpgrade(CPosition pos, char symbole, unsigned short augmentation);
	CTorcheUpgrade(short x, short y, char symbole, unsigned short augmentation);
	CTorcheUpgrade(short x, short y, char symbole);

	unsigned short getPortee();
	static const char SYMBOLE_DEFAUT = '#';
	static const short PORTEE_DEFAUT = 3;
	static const int PORTEE_MAX = 9;

	void UseItem(CPersonnage &perso) override;


	static char GetSymbole() { return SYMBOLE_DEFAUT; };

private:
	unsigned  short portee_;
};