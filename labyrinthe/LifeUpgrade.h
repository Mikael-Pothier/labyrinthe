#include "Item.h";
#pragma once;

class LifeUpgrade : public CItem
{
public:
	LifeUpgrade(CPosition pos, char Symbole,unsigned short duree);
	LifeUpgrade(CPosition pos,char Symbole,unsigned short duree,unsigned short augmentation);
	LifeUpgrade(short x,short y, char Symbole,unsigned short duree,unsigned short augmentation);
	LifeUpgrade(short x,short y, char Symbole,unsigned short duree);

	unsigned short getNbPas();

private:
	unsigned  short NbPas_;
	const short NbPasDefaut=10;

};