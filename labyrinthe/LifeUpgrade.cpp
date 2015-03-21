#include "LifeUpgrade.h";

LifeUpgrade::LifeUpgrade(CPosition pos, char Symbole,unsigned short duree) : CItem(pos,Symbole,duree)
{
	NbPas_= NbPasDefaut;
}

LifeUpgrade::LifeUpgrade(CPosition pos, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(pos,Symbole,duree)
{
	if(augmentation >0)
		NbPas_=augmentation;
	else
		NbPas_= NbPasDefaut;
}

LifeUpgrade::LifeUpgrade(short x,short y, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(x,y,Symbole,duree) 
{
	if(augmentation >0)
		NbPas_=augmentation;
	else
		NbPas_= NbPasDefaut;
}

LifeUpgrade::LifeUpgrade(short x,short y, char Symbole,unsigned short duree): CItem(x,y,Symbole,duree)
{
	NbPas_= NbPasDefaut;
}

unsigned short LifeUpgrade::getNbPas()
{
	return NbPas_;
}