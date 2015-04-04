#include "TorcheUpgrade.h";

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole) : CItem(pos, Symbole)
{
	portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, unsigned short augmentation) : CItem(pos, Symbole)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
		portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, unsigned short augmentation) : CItem(x, y, Symbole)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
		portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole) : CItem(x, y, Symbole)
{
	portee_ = PORTEE_DEFAUT;
}

unsigned short CTorcheUpgrade::getPortee()
{
	return portee_;
}

void CTorcheUpgrade::UseItem(CPersonnage &perso)
{
	if (perso.GetVision() + portee_ <= PORTEE_MAX)
		perso.SetVision(perso.GetVision() + portee_);
	else
		perso.SetVision(PORTEE_MAX);
}