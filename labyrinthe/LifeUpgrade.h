#pragma once;
#include "Item.h";

class CLifeUpgrade : public CItem
{
public:
	CLifeUpgrade(CPosition pos, char symbole, unsigned short duree);
	CLifeUpgrade(CPosition pos, char symbole, unsigned short duree, unsigned short augmentation);
	CLifeUpgrade(short x, short y, char symbole, unsigned short duree, unsigned short augmentation);
	CLifeUpgrade(short x, short y, char symbole, unsigned short duree);

	unsigned short getNbPas();

private:
	unsigned  short nb_pas_;
	const short NB_PAS_DEFAUT = 10;

};