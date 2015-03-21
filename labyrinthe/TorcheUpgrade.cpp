#include "TorcheUpgrade.h";

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, unsigned short duree) : CItem(pos, Symbole, duree)
{
	portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, unsigned short duree, unsigned short augmentation) : CItem(pos, Symbole, duree)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
		portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, unsigned short duree, unsigned short augmentation) : CItem(x, y, Symbole, duree)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
		portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, unsigned short duree) : CItem(x, y, Symbole, duree)
{
	portee_ = PORTEE_DEFAUT;
}

unsigned short CTorcheUpgrade::getPortee()
{
	return portee_;
}