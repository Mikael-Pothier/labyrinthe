#include "TorcheUpgrade.h";

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, 
							   unsigned short augmentation, unsigned short duree)
							   : CItem(pos, Symbole, duree, augmentation)
{

}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, 
							   unsigned short augmentation, unsigned short duree) 
							   : CItem(CPosition(x, y), Symbole, duree, augmentation)
{

}