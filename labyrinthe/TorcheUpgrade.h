#include "Item.h";
#pragma once;

class CTorcheUpgrade : public CItem
{
public:
	CTorcheUpgrade(CPosition pos, char Symbole,unsigned short duree);
	CTorcheUpgrade(CPosition pos,char Symbole,unsigned short duree,unsigned short augmentation);
	CTorcheUpgrade(short x,short y, char Symbole,unsigned short duree,unsigned short augmentation);
	CTorcheUpgrade(short x,short y, char Symbole,unsigned short duree);

	unsigned short getPortee();

private:
	unsigned  short Portee_;
	const short PorteeDefaut=3;

};