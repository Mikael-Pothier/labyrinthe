#pragma once;
#include "Item.h";

class CTorcheUpgrade : public CItem
{
	unsigned  short portee_;
public:
	static const char SYMBOLE_DEFAUT = '#';
	static const short BONUS_DEFAUT = 2;
	static const int PORTEE_MAX = 11;
	static const unsigned short DUREE_DEFAUT = 10;

	CTorcheUpgrade(CPosition pos, char symbole = SYMBOLE_DEFAUT, 
				   unsigned short augmentation = BONUS_DEFAUT, 
				   unsigned short duree = DUREE_DEFAUT);

	CTorcheUpgrade(short x, short y, char symbole = SYMBOLE_DEFAUT, 
				   unsigned short augmentation = BONUS_DEFAUT,
				   unsigned short duree = DUREE_DEFAUT);

	void UtiliserItem(CPersonnage &perso) override;
};