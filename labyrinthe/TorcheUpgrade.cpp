#include "TorcheUpgrade.h";


CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole, unsigned short augmentation, unsigned short duree) : CItem(pos, Symbole,duree)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
		portee_ = PORTEE_DEFAUT;
}

CTorcheUpgrade::CTorcheUpgrade(short x, short y, char Symbole, unsigned short augmentation, unsigned short duree) : CItem(x, y, Symbole,duree)
{
	if (augmentation > 0)
		portee_ = augmentation;
	else
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

	perso.AjouterDuree(GetSymbole(), getduree());
}