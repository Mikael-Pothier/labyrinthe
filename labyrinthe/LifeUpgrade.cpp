#include "LifeUpgrade.h";

CLifeUpgrade::CLifeUpgrade(CPosition pos, char Symbole) : CItem(pos,Symbole)
{
	nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(CPosition pos, char Symbole,unsigned short augmentation) : CItem(pos,Symbole)
{
	if(augmentation >0)
		nb_pas_=augmentation;
	else
		nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(short x,short y, char Symbole,unsigned short augmentation) : CItem(x,y,Symbole) 
{
	if(augmentation >0)
		nb_pas_=augmentation;
	else
		nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(short x,short y, char Symbole): CItem(x,y,Symbole)
{
	nb_pas_= NB_PAS_DEFAUT;
}

unsigned short CLifeUpgrade::getNbPas()
{
	return nb_pas_;
}