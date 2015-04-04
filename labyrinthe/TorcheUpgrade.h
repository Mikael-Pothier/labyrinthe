#pragma once;
#include "Item.h";

class CTorcheUpgrade : public CItem
{
public:
	CTorcheUpgrade(CPosition pos, char symbole, unsigned short duree);
	CTorcheUpgrade(CPosition pos, char symbole, unsigned short duree, unsigned short augmentation);
	CTorcheUpgrade(short x, short y, char symbole, unsigned short duree, unsigned short augmentation);
	CTorcheUpgrade(short x, short y, char symbole, unsigned short duree);

	unsigned short getPortee();
	static const char SYMBOLE_DEFAUT = '#';
	static const short PORTEE_DEFAUT = 3;

private:
	unsigned  short portee_;
};