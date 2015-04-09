#include "TorcheUpgrade.h";


CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, unsigned short augmentation, unsigned short duree) : CItem(pos, Symbole, duree, augmentation)
{

}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, unsigned short augmentation, unsigned short duree) : CItem(CPosition(x, y), Symbole, duree, augmentation)
{

}

void CTorcheUpgrade::UtiliserItem(CPersonnage &perso)
{
	if (perso.GetVision() + GetBonus() <= PORTEE_MAX)
		perso.SetVision(perso.GetVision() + GetBonus());
	else
		perso.SetVision(PORTEE_MAX);
}