#pragma once;
#include "Item.h";

class CTorcheUpgrade : public CItem
{
public:
	CTorcheUpgrade(CPosition pos, char symbole = SYMBOLE_DEFAUT, unsigned short augmentation = PORTEE_DEFAUT, unsigned short duree = DUREE_DEFAUT);
	CTorcheUpgrade(short x, short y, char symbole = SYMBOLE_DEFAUT, unsigned short augmentation = PORTEE_DEFAUT, unsigned short duree = DUREE_DEFAUT);

	unsigned short getPortee();
	static const char SYMBOLE_DEFAUT = '#';
	static const short PORTEE_DEFAUT = 2;
	static const int PORTEE_MAX = 11;
	static const unsigned short DUREE_DEFAUT = 5;

	void UseItem(CPersonnage &perso) override;


	static char GetSymbole() { return SYMBOLE_DEFAUT; };

private:
	unsigned  short portee_;
};