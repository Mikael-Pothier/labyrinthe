#include "LifeUpgrade.h";

CLifeUpgrade::CLifeUpgrade(CPosition pos, char Symbole,unsigned short duree) : CItem(pos,Symbole,duree)
{
	nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(CPosition pos, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(pos,Symbole,duree)
{
	if(augmentation >0)
		nb_pas_=augmentation;
	else
		nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(short x,short y, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(x,y,Symbole,duree) 
{
	if(augmentation >0)
		nb_pas_=augmentation;
	else
		nb_pas_= NB_PAS_DEFAUT;
}

CLifeUpgrade::CLifeUpgrade(short x,short y, char Symbole,unsigned short duree): CItem(x,y,Symbole,duree)
{
	nb_pas_= NB_PAS_DEFAUT;
}

unsigned short CLifeUpgrade::getNbPas()
{
	return nb_pas_;
}