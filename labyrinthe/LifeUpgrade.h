#pragma once;
#include "Item.h";

class CLifeUpgrade : public CItem
{
	unsigned  short nb_pas_;
public:

	CLifeUpgrade(CPosition pos, char symbole = SYMBOLE_DEFAUT, 
				 unsigned short augmentation = BONUS_DEFAUT);

	CLifeUpgrade(short x, short y, char symbole = SYMBOLE_DEFAUT, 
				 unsigned short augmentation = BONUS_DEFAUT);

	static const short BONUS_DEFAUT = 15;
	static const char SYMBOLE_DEFAUT = '$';

	void UtiliserItem(CPersonnage &perso) override
	{ 
		perso.SetNbPas(perso.GetNbPas() + GetBonus()); 
	}
};