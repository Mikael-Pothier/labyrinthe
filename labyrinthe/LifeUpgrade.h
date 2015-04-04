#pragma once;
#include "Item.h";

class CLifeUpgrade : public CItem
{
public:
	CLifeUpgrade(CPosition pos, char symbole);
	CLifeUpgrade(CPosition pos, char symbole, unsigned short augmentation);
	CLifeUpgrade(short x, short y, char symbole, unsigned short augmentation);
	CLifeUpgrade(short x, short y, char symbole);

	unsigned short getNbPas();

	static const short NB_PAS_DEFAUT = 15;
	static const char SYMBOLE_DEFAUT = '$';

	void UseItem(CPersonnage &perso);

private:
	unsigned  short nb_pas_;

};